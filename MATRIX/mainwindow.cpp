#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QToolBar>
#include <QUrl>
#include <QWebEngineHistory>
#include <QMessageBox>
#include <QSettings>
#include <QDockWidget>
#include <QMessageBox>
#include <QWebEngineSettings>
#include <QWebEngineProfile>
#include <QWebEngineDownloadRequest>
#include <QFileDialog>
#include<QStandardPaths>
#include<QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create main layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // --- Tab Bar Layout ---
    tabBar = new QTabBar(this);
    tabBar->setTabsClosable(true);
    tabBar->setMovable(true);
    tabBar->setExpanding(false);
    tabBar->setLayoutDirection(Qt::LeftToRight); // Ensure tabs appear from left to right

    // Set tab size larger
    tabBar->setStyleSheet("QTabBar::tab { height: 30px; width: 150px; font-size: 14px; }");

    // Ensure correct connections
    connect(tabBar, &QTabBar::currentChanged, this, &MainWindow::switchTab);
    connect(tabBar, &QTabBar::tabCloseRequested, this, &MainWindow::closeTab);

    // "+" Button next to tabs, shifts as new tabs are added
    newTabButton = new QPushButton("+", this);
    newTabButton->setFixedSize(40, 30); // Slightly larger for better visibility
    connect(newTabButton, &QPushButton::clicked, this, &MainWindow::addNewTab);

    // Layout for tab bar and "+" button
    QHBoxLayout *tabLayout = new QHBoxLayout();
    tabLayout->addWidget(tabBar);
    tabLayout->addWidget(newTabButton); // Keeps "+" button immediately after tabs
    tabLayout->addStretch();  // Pushes extra space to the right

    layout->addLayout(tabLayout);


    // URL Bar
    urlBar = new QLineEdit(this);
    connect(urlBar, &QLineEdit::returnPressed, this, QOverload<>::of(&MainWindow::navigateToUrl));

    // Navigation Buttons
    backButton = new QPushButton("⏪", this);
    forwardButton = new QPushButton("⏩", this);
    reloadButton = new QPushButton("🔄", this);

    // Sidebar Buttons
    historyButton = new QPushButton("📜", this);
    bookmarkButton = new QPushButton("⭐", this);
    addBookmarkButton = new QPushButton("➕", this);
    downloadsButton = new QPushButton("📥", this);

    // Prevent full width expansion
    backButton->setFixedSize(40, 30);
    forwardButton->setFixedSize(40, 30);
    reloadButton->setFixedSize(40, 30);

    historyButton->setFixedSize(40, 30);
    bookmarkButton->setFixedSize(40, 30);
    addBookmarkButton->setFixedSize(40, 30);
    downloadsButton->setFixedSize(40, 30);

    // Create navigation layout (horizontal row)
    QHBoxLayout *navLayout = new QHBoxLayout();
    navLayout->addWidget(backButton);
    navLayout->addWidget(forwardButton);
    navLayout->addWidget(reloadButton);
    navLayout->addWidget(urlBar);
    navLayout->addWidget(historyButton);
    navLayout->addWidget(bookmarkButton);
    navLayout->addWidget(addBookmarkButton);
    navLayout->addWidget(downloadsButton);

    // Add navigation layout to the main layout
    layout->addLayout(navLayout);

    // Set up button connections
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goBack);
    connect(forwardButton, &QPushButton::clicked, this, &MainWindow::goForward);
    connect(reloadButton, &QPushButton::clicked, this, &MainWindow::reloadPage);

    connect(historyButton, &QPushButton::clicked, this, &MainWindow::showHistory);
    connect(bookmarkButton, &QPushButton::clicked, this, &MainWindow::showBookmarks);
    connect(addBookmarkButton, &QPushButton::clicked, this, &MainWindow::addBookmark);
    connect(downloadsButton, &QPushButton::clicked, this, &MainWindow::showDownloads);

    // Create stacked widget for browser tabs
    tabContainer = new QStackedWidget(this);
    layout->addWidget(tabContainer);

    historyDock = new QDockWidget("History", this);
    bookmarkDock = new QDockWidget("Bookmarks", this);
    downloadDock = new QDockWidget("Downloads", this);

    // Initialize history and bookmarks widgets
    historyListWidget = new QListWidget(this);
    bookmarkListWidget = new QListWidget(this);
    downloadListWidget = new QListWidget(this);

    connect(historyListWidget, &QListWidget::itemActivated, this, &MainWindow::openFromHistory);
    connect(bookmarkListWidget, &QListWidget::itemActivated, this, &MainWindow::openFromBookmarks);
    connect(downloadListWidget, &QListWidget::itemActivated, this, &MainWindow::openDownloadedFile);

    // Create Buttons
    clearHistoryButton = new QPushButton("Clear All", this);
    clearSelectedHistoryButton = new QPushButton("Clear Selected", this);

    clearBookmarksButton = new QPushButton("Clear All", this);
    clearSelectedBookmarkButton = new QPushButton("Clear Selected", this);

    clearDownloadsButton = new QPushButton("Clear All", this);
    clearSelectedDownloadButton = new QPushButton("Clear Selected", this);

    // Connect Buttons to Functions
    connect(clearHistoryButton, &QPushButton::clicked, this, &MainWindow::clearAllHistory);
    connect(clearSelectedHistoryButton, &QPushButton::clicked, this, &MainWindow::clearSelectedHistory);

    connect(clearBookmarksButton, &QPushButton::clicked, this, &MainWindow::clearAllBookmarks);
    connect(clearSelectedBookmarkButton, &QPushButton::clicked, this, &MainWindow::clearSelectedBookmark);

    connect(clearDownloadsButton, &QPushButton::clicked, this, &MainWindow::clearAllDownloads);
    connect(clearSelectedDownloadButton, &QPushButton::clicked, this, &MainWindow::clearSelectedDownload);

    // Add Buttons to the Docks
    QVBoxLayout *historyLayout = new QVBoxLayout();
    historyLayout->addWidget(historyListWidget);
    historyLayout->addWidget(clearSelectedHistoryButton);
    historyLayout->addWidget(clearHistoryButton);
    QWidget *historyContainer = new QWidget();
    historyContainer->setLayout(historyLayout);
    historyDock->setWidget(historyContainer);
    addDockWidget(Qt::RightDockWidgetArea, historyDock);
    historyDock->hide();

    QVBoxLayout *bookmarkLayout = new QVBoxLayout();
    bookmarkLayout->addWidget(bookmarkListWidget);
    bookmarkLayout->addWidget(clearSelectedBookmarkButton);
    bookmarkLayout->addWidget(clearBookmarksButton);
    QWidget *bookmarkContainer = new QWidget();
    bookmarkContainer->setLayout(bookmarkLayout);
    bookmarkDock->setWidget(bookmarkContainer);
    addDockWidget(Qt::RightDockWidgetArea, bookmarkDock);
    bookmarkDock->hide();

    QVBoxLayout *downloadLayout = new QVBoxLayout();
    downloadLayout->addWidget(downloadListWidget);
    downloadLayout->addWidget(clearSelectedDownloadButton);
    downloadLayout->addWidget(clearDownloadsButton);
    QWidget *downloadContainer = new QWidget();
    downloadContainer->setLayout(downloadLayout);
    downloadDock->setWidget(downloadContainer);
    addDockWidget(Qt::RightDockWidgetArea, downloadDock);
    downloadDock->hide();

    //download requests
    connect(QWebEngineProfile::defaultProfile(), &QWebEngineProfile::downloadRequested, this, &MainWindow::handleDownload);

    // Set the central widget after adding everything
    setCentralWidget(centralWidget);
    loadHistory();
    loadBookmarks();
    loadDownloads();
    addNewTab();
}

void MainWindow::addNewTab()
{
    QWebEngineView *browser = new QWebEngineView();

    // Enable Performance Enhancements
    browser->settings()->setAttribute(QWebEngineSettings::Accelerated2dCanvasEnabled, true);
    browser->settings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);
    browser->settings()->setAttribute(QWebEngineSettings::ScreenCaptureEnabled, true);
    browser->settings()->setAttribute(QWebEngineSettings::JavascriptCanOpenWindows, true);
    browser->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    browser->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);

    browser->settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    browser->settings()->setAttribute(QWebEngineSettings::AutoLoadImages, true);
    browser->settings()->setAttribute(QWebEngineSettings::DnsPrefetchEnabled, true);

    browser->page()->setLifecycleState(QWebEnginePage::LifecycleState::Active);

    browser->setUrl(QUrl("https://www.google.com"));

    connect(browser, &QWebEngineView::urlChanged, this, &MainWindow::updateUrlBar);
    connect(browser, &QWebEngineView::urlChanged, this, &MainWindow::updateHistory);

    int index = tabBar->addTab("New Tab");
    tabContainer->addWidget(browser);
    tabBar->setCurrentIndex(index);
    tabContainer->setCurrentIndex(index);
}



void MainWindow::switchTab(int index)
{
    tabContainer->setCurrentIndex(index);
}

void MainWindow::closeTab(int index)
{
    if (tabBar->count() > 1) {
        QWidget *widget = tabContainer->widget(index);
        tabContainer->removeWidget(widget);
        tabBar->removeTab(index);
        if (widget) {
            delete widget;
        }
    } else {
        QMessageBox::warning(this, "Warning", "You cannot close the last tab.");
    }
}

void MainWindow::navigateToUrl()
{
    QWebEngineView *browser = qobject_cast<QWebEngineView *>(tabContainer->currentWidget());
    if (browser) {
        browser->setUrl(QUrl::fromUserInput(urlBar->text()));
    }
}


void MainWindow::navigateToUrl(QUrl url)
{
    QWebEngineView *browser = qobject_cast<QWebEngineView *>(tabContainer->currentWidget());
    if (browser) {
        browser->setUrl(url);
    }
}

void MainWindow::updateUrlBar(QUrl url)
{
    QString cleanUrl = url.toString(QUrl::RemoveFragment | QUrl::StripTrailingSlash);
    urlBar->setText(cleanUrl);
    tabBar->setTabText(tabBar->currentIndex(), url.host());
}


void MainWindow::goBack()
{
    QWebEngineView *browser = qobject_cast<QWebEngineView *>(tabContainer->currentWidget());
    if (browser) {
        browser->back();
    }
}

void MainWindow::goForward()
{
    QWebEngineView *browser = qobject_cast<QWebEngineView *>(tabContainer->currentWidget());
    if (browser) {
        browser->forward();
    }
}

void MainWindow::reloadPage()
{
    QWebEngineView *browser = qobject_cast<QWebEngineView *>(tabContainer->currentWidget());
    if (browser) {
        browser->reload();
    }
}

void MainWindow::updateHistory(const QUrl &url)
{
    QString urlStr = url.toString();
    if (!historyList.contains(urlStr)) {
        historyList.append(urlStr);

        QListWidgetItem *item = new QListWidgetItem(urlStr, historyListWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        historyListWidget->addItem(item);

        saveHistory();
    }
}

void MainWindow::addBookmark()
{
    QWebEngineView *browser = qobject_cast<QWebEngineView *>(tabContainer->currentWidget());
    if (browser) {
        QString url = browser->url().toString();
        if (!bookmarks.contains(url)) {
            bookmarks.append(url);

            QListWidgetItem *item = new QListWidgetItem(url, bookmarkListWidget);
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            item->setCheckState(Qt::Unchecked);
            bookmarkListWidget->addItem(item);

            QMessageBox::information(this, "", "Added to Bookmarks");
            saveBookmarks();
        }
    }
}

void MainWindow::showHistory()
{
    historyDock->setVisible(!historyDock->isVisible());
}

void MainWindow::showBookmarks()
{
    bookmarkDock->setVisible(!bookmarkDock->isVisible());
}

void MainWindow::openFromHistory(QListWidgetItem *item)
{
    navigateToUrl(QUrl(item->text()));
}

void MainWindow::openFromBookmarks(QListWidgetItem *item)
{
    navigateToUrl(QUrl(item->text()));
}

void MainWindow::loadHistory()
{
    QSettings settings("MyBrowser", "History");
    historyList = settings.value("historyList").toStringList();

    for (const QString &url : historyList) {
        QListWidgetItem *item = new QListWidgetItem(url, historyListWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        historyListWidget->addItem(item);
    }
}


void MainWindow::saveHistory()
{
    QSettings settings("MyBrowser", "History");
    settings.setValue("historyList", historyList);
}

void MainWindow::loadBookmarks()
{
    QSettings settings("MyBrowser", "Bookmarks");
    bookmarks = settings.value("bookmarkList").toStringList();

    for (const QString &url : bookmarks) {
        QListWidgetItem *item = new QListWidgetItem(url, bookmarkListWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        bookmarkListWidget->addItem(item);
    }
}

void MainWindow::saveBookmarks()
{
    QSettings settings("MyBrowser", "Bookmarks");
    settings.setValue("bookmarkList", bookmarks);
}

void MainWindow::handleDownload(QWebEngineDownloadRequest *download)
{
    if (!download)
        return;

    // Choose download location
    QString filePath = QFileDialog::getSaveFileName(
        this, "Save File", QStandardPaths::writableLocation(QStandardPaths::DownloadLocation) + "/" + download->downloadFileName()
        );

    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Download Cancelled", "No file selected.");
        return;
    }

    // Set file path and accept download
    download->setDownloadFileName(QFileInfo(filePath).fileName());
    download->setDownloadDirectory(QFileInfo(filePath).absolutePath());
    download->accept();

    // Add to downloads list
    downloadsList.append(filePath);
    QListWidgetItem *item = new QListWidgetItem(download->downloadFileName() + " - Downloading... ⏳", downloadListWidget);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    item->setData(Qt::UserRole, filePath);
    downloadListWidget->addItem(item);

    // Track state changes
    connect(download, &QWebEngineDownloadRequest::stateChanged, this, &MainWindow::updateDownloadState);

    downloadDock->show();
    saveDownloads();
}


void MainWindow::updateDownloadState(QWebEngineDownloadRequest::DownloadState state)
{
    QListWidgetItem *item = downloadListWidget->item(downloadListWidget->count() - 1);
    if (!item) return;

    QString status;
    switch (state) {
    case QWebEngineDownloadRequest::DownloadCompleted: status = "Completed ✅"; break;
    case QWebEngineDownloadRequest::DownloadCancelled: status = "Cancelled ❌"; break;
    case QWebEngineDownloadRequest::DownloadInterrupted: status = "Failed ⚠️"; break;
    default: status = "Downloading... ⏳"; break;
    }

    item->setText(item->text().split(" - ")[0] + " - " + status);
}


void MainWindow::showDownloads()
{
    downloadDock->setVisible(!downloadDock->isVisible());
}

void MainWindow::openDownloadedFile(QListWidgetItem *item)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(item->data(Qt::UserRole).toString()));
}


void MainWindow::loadDownloads()
{
    QSettings settings("MyBrowser", "Downloads");
    downloadsList = settings.value("downloadList").toStringList();

    for (const QString &filePath : downloadsList) {
        QListWidgetItem *item = new QListWidgetItem(QFileInfo(filePath).fileName() + " - Completed ✅", downloadListWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        item->setData(Qt::UserRole, filePath);
        downloadListWidget->addItem(item);
    }
}
void MainWindow::saveDownloads()
{
    QSettings settings("MyBrowser", "Downloads");
    settings.setValue("downloadList", downloadsList);
}

void MainWindow::clearAllHistory()
{
    historyList.clear();
    historyListWidget->clear();
    saveHistory();
    QMessageBox::information(this, "History Cleared", "All history items have been removed.");
}

void MainWindow::clearSelectedHistory()
{
    for (int i = historyListWidget->count() - 1; i >= 0; --i) {
        QListWidgetItem *item = historyListWidget->item(i);
        if (item->checkState() == Qt::Checked) {
            historyList.removeAll(item->text());
            delete historyListWidget->takeItem(i);
        }
    }
    saveHistory();
}


void MainWindow::clearAllBookmarks()
{
    bookmarks.clear();
    bookmarkListWidget->clear();
    saveBookmarks();
    QMessageBox::information(this, "Bookmarks Cleared", "All bookmarks have been removed.");
}

void MainWindow::clearSelectedBookmark()
{
    for (int i = bookmarkListWidget->count() - 1; i >= 0; --i) {
        QListWidgetItem *item = bookmarkListWidget->item(i);
        if (item->checkState() == Qt::Checked) {
            bookmarks.removeAll(item->text());
            delete bookmarkListWidget->takeItem(i);
        }
    }
    saveBookmarks();
}


void MainWindow::clearAllDownloads()
{
    downloadsList.clear();
    downloadListWidget->clear();
    saveDownloads();
    QMessageBox::information(this, "Downloads Cleared", "All downloads have been removed.");
}

void MainWindow::clearSelectedDownload()
{
    for (int i = downloadListWidget->count() - 1; i >= 0; --i) {
        QListWidgetItem *item = downloadListWidget->item(i);
        if (item->checkState() == Qt::Checked) {
            downloadsList.removeAll(item->data(Qt::UserRole).toString());
            delete downloadListWidget->takeItem(i);
        }
    }
    saveDownloads();
}


MainWindow::~MainWindow()
{
    saveHistory();
    saveBookmarks();
    saveDownloads();
    delete ui;
}

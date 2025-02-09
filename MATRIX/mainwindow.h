#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabBar>
#include <QStackedWidget>
#include <QWebEngineView>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QDockWidget>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addNewTab();
    void switchTab(int index);
    void closeTab(int index);
    void navigateToUrl();
    void navigateToUrl(QUrl url);
    void updateUrlBar(QUrl url);
    void goBack();
    void goForward();
    void reloadPage();
    void updateHistory(const QUrl &url);
    void addBookmark();
    void showHistory();
    void showBookmarks();
    void openFromHistory(QListWidgetItem *item);
    void openFromBookmarks(QListWidgetItem *item);
    void handleDownload(QWebEngineDownloadRequest *download);
    void updateDownloadState(QWebEngineDownloadRequest::DownloadState state);
    void showDownloads();
    void openDownloadedFile(QListWidgetItem *item);
    void clearAllHistory();
    void clearSelectedHistory();
    void clearAllBookmarks();
    void clearSelectedBookmark();
    void clearAllDownloads();
    void clearSelectedDownload();



private:
    Ui::MainWindow *ui;

    QTabBar *tabBar;
    QStackedWidget *tabContainer;
    QPushButton *newTabButton;

    // Navigation buttons
    QPushButton *backButton;
    QPushButton *forwardButton;
    QPushButton *reloadButton;

    // URL bar
    QLineEdit *urlBar;

    // Sidebar buttons
    QPushButton *historyButton;
    QPushButton *bookmarkButton;
    QPushButton *addBookmarkButton;
    QPushButton *downloadsButton;

    QStringList historyList;
    QStringList bookmarks;
    QStringList downloadsList;

    QListWidget *historyListWidget;
    QListWidget *bookmarkListWidget;

    QPushButton *clearHistoryButton;
    QPushButton *clearSelectedHistoryButton;
    QPushButton *clearBookmarksButton;
    QPushButton *clearSelectedBookmarkButton;
    QPushButton *clearDownloadsButton;
    QPushButton *clearSelectedDownloadButton;

    QDockWidget *historyDock;
    QDockWidget *bookmarkDock;

    QListWidget *downloadListWidget;
    QDockWidget *downloadDock;

    void loadHistory();
    void saveHistory();
    void loadBookmarks();
    void saveBookmarks();
    void loadDownloads();
    void saveDownloads();
};
#endif // MAINWINDOW_H

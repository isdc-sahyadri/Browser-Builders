import requests
from bs4 import BeautifulSoup
import json
import os

class Crawler:
    def __init__(self):
        self.visited_urls = set()
        self.data = {}

    def crawl(self, url, depth=1):
        """Crawls the given URL and extracts text content."""
        if depth == 0 or url in self.visited_urls:
            return

        try:
            response = requests.get(url, timeout=5)
            if response.status_code != 200:
                return

            soup = BeautifulSoup(response.text, "html.parser")
            text = soup.get_text(separator=" ", strip=True)

            self.visited_urls.add(url)
            self.data[url] = text  # Store text content

            # Find and crawl links
            for link in soup.find_all("a", href=True):
                next_url = link["href"]
                if next_url.startswith("http"):  # Avoid relative URLs
                    self.crawl(next_url, depth - 1)

        except Exception as e:
            print(f"Error crawling {url}: {e}")

    def save_data(self, filename="../data/crawled_pages.json"):
        """Saves the crawled data as JSON."""
        os.makedirs(os.path.dirname(filename), exist_ok=True)
        with open(filename, "w", encoding="utf-8") as f:
            json.dump(self.data, f, indent=4)

# Run the crawler
if __name__ == "__main__":
    crawler = Crawler()
    crawler.crawl("https://example.com", depth=2)
    crawler.save_data()
    print("Crawling complete! Data saved to crawled_pages.json.")

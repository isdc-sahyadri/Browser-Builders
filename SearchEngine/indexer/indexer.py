from indexer.tokenizer import Tokenizer
import json
import os

class Indexer:
    def __init__(self):
        self.tokenizer = Tokenizer()
        self.index = {}

    def index_document(self, url, text):
        tokens = self.tokenizer.tokenize(text)
        for token in tokens:
            if token not in self.index:
                self.index[token] = set()
            self.index[token].add(url)

    def build_index(self, input_file="../data/crawled_pages.json"):
        """Loads crawled data and builds an index."""
        if not os.path.exists(input_file):
            print(f"Error: {input_file} not found! Run the crawler first.")
            return

        with open(input_file, "r", encoding="utf-8") as f:
            pages = json.load(f)

        for url, text in pages.items():
            self.index_document(url, text)

    def save_index(self, filename="../data/index.json"):
        """Saves the index to JSON format."""
        os.makedirs(os.path.dirname(filename), exist_ok=True)
        with open(filename, "w") as f:
            json.dump({k: list(v) for k, v in self.index.items()}, f)

# Run the indexer
if __name__ == "__main__":
    indexer = Indexer()
    indexer.build_index()
    indexer.save_index()
    print("Indexing complete! Data saved to index.json.")

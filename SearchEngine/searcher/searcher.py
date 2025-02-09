import json
import os
from ranking import Ranking

class Searcher:
    def __init__(self):
        self.index_file = '../data/index.json'
        self.index = {}

        # Load index if it exists, otherwise warn the user
        if os.path.exists(self.index_file):
            with open(self.index_file) as f:
                self.index = json.load(f)
        else:
            print("Warning: index.json not found! Run the indexer first.")

    def search(self, query):
        query_tokens = query.lower().split()
        results = {}

        for token in query_tokens:
            if token in self.index:
                for url in self.index[token]:
                    results[url] = results.get(url, 0) + 1

        return sorted(results.items(), key=lambda x: x[1], reverse=True)

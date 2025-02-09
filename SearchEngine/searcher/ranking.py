class Ranking:
    def rank(self, results):
        # Basic ranking based on frequency of tokens in documents
        return sorted(results.items(), key=lambda x: x[1], reverse=True)

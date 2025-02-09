import re
import string

class Tokenizer:
    def __init__(self):
        # Define characters to be removed and word separators
        self.pattern = re.compile(r'\b\w+\b')  # Matches words
    
    def tokenize(self, text):
        """
        Tokenizes input text by removing punctuation and converting to lowercase.
        """
        text = text.lower()  # Convert text to lowercase
        tokens = self.pattern.findall(text)  # Extract words using regex
        return tokens

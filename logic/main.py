from sklearn.feature_extraction.text import TfidfVectorizer
import numpy as np

def compare(file1, file2):
    documents = [open(f).read() for f in [file1, file2]]
    tfidf = TfidfVectorizer().fit_transform(documents)
    pairwise_similarity = tfidf * tfidf.T

    arr = pairwise_similarity.toarray()
    np.fill_diagonal(arr, np.nan)
    similarity = arr[0][1]
    # print(f"Similarity: {round(similarity * 100, 2)}%")
    return round(similarity * 100, 2)
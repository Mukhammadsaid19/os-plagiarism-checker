import re

if __name__ == '__main__':
    with open("file1") as f:
        file1 = f.read().lower()
    with open("file2") as f:
        file2 = f.read().lower()

    if file1 == file2:
        similarity = 100
    else:
        sen = [i.strip() for i in re.split(r'\n|(?<!\d)[,.](?!\d)', file1)]
        match_list = [0 for _ in range(len(sen))]
        for i, v in enumerate(sen):
            if re.search(v, file2):
                match_list[i] = 1

        similarity = round(sum(match_list) / len(match_list) * 100, 2)
    print(f"Similarity: {similarity}%")

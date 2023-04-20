def generate_n(words, n):
    words.sort()
    items=list(range(len(words)))
    combination_1=[]
    for i in items:
        combination_1.append([i])
    combination=combination_1
    combination_3=[combination]
    for x in range(1,n):
        combination=[]
        for i in combination_1:
            for j in items:
                if(j>i[-1]):
                    combination.append(i+[j])
        combination_1=combination
        combination_3.append(combination)
    word_combinations=[]
    for k in combination_3:
        for i in k:
            line=[]
            for j in i:
                line.append(words[j])
            word_combinations.append(tuple(line))
    return sorted(set(word_combinations))

sentence=input()
word=sentence.split()
combinations=generate_n(word, len(word))
for i in combinations:
    print(" ".join(j))
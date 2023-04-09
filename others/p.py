def generate_3(words):
    words.sort()
    items=list(range(len(words)))
    combination_1=[]
    for i in items:
        combination_1.append([i])
    combination_2=[]
    for i in combination_1:
        for j in items:
            if(j>i[-1]):
                combination_2.append(i+[j])
    combination_3=[]
    for i in combination_2:
        for j in items:
            if(j>i[-1]):
                combination_3.append(i+[j])
    word_combinations=[]
    for i in combination_3:
        line=[]
        for j in i:
            line.append(words[j])
        word_combinations.append(tuple(line))
    return sorted(set(word_combinations))

sentence=input()
word=sentence.split()
combinations=generate_3(word)
for i in combinations:
    print(" ".join(i))


'''
a bag bag
a bag big
a bag in
a bag is
a bag small
a bag there
a big ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin ii iin in
a big is
a big small
a big there
a in is
a in small
a in there
a is small
a is there
a small there
bag bag big
bag bag in
bag bag is
bag bag small
bag bag there
bag big in
bag big is
bag big small
bag big there
bag in is
bag in small
bag in there
bag is small
bag is there
bag small there
big in is
big in small
big in there
big is small
big is there
big small there
in is small
in is there
in small there
is small there

'''
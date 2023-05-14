from time import *
from sys import *

class text:
  HEADER = '\033[95m'
  OKBLUE = '\033[94m'
  OKCYAN = '\033[96m'
  OKGREEN = '\033[92m'
  WARNING = '\033[93m'
  FAIL = '\033[91m'
  NEUTRAL = '\033[0m'
  BOLD = '\033[1m'
  UNDERLINE = '\033[4m'
  LOADING = '\033[33m'
  QUESTION = '\033[34m'
    

def check(i):
  j = ""
  for m in i:
    if(m == 'i'):
      j = j + '1'
    elif(m == 'w'):
      j = j + '2'
    elif(m == 'k'):
      j = j + '3'
    elif(m == 't'):
      j = j + '4'
    elif(m == 'y'):
      j = j + '5'
    elif(m == 'p'):
      j = j + '6'
    elif(m == 'q'):
      j = j + '7'
    elif(m == 'e'):
      j = j + '8'
    elif(m == 'r'):
      j = j + '9'
    elif(m == 'u'):
      j = j + '0'
    elif(m == 's'):
      j = j + '@'
    elif(m == 'o'):
      j = j + 'O'
    elif(m == 'a'):
      j = j + '!'
    elif(m == 'd'):
      j = j + '#'
    elif(m == 'm'):
      j = j + '$'
    elif(m == 'h'):
      j = j + ')'
    elif(m == 'g'):
      j = j + '%'
    elif(m == 'f'):
      j = j + '('
    elif(m == 'j'):
      j = j + '*'
    elif(m == 'l'):
      j = j + '['
    elif(m == 'z'):
      j = j + 'H'
    elif(m == 'x'):
      j = j + 'n'
    elif(m == 'c'):
      j = j + 'w'
    elif(m == 'v'):
      j = j + '.'
    elif(m == 'b'):
      j = j + 'i'
    elif(m == 'n'):
      j = j + '?'
    elif(m == ' '):
      j = j + ']'
    elif(m == '('):
      j = j + 'q'
    elif(m == ')'):
      j = j + 'k'
    elif(m == '.'):
      j = j + '<'
    elif(m == "B"):
      j = j + "P"
    elif(m == '\''):
      j = j + '>'
    elif(m == '"'):
      j = j + 'T'
    elif(m == "G"):
      j = j + "X"
    elif(m == "H"):
      j = j + "z"
    elif(m == "A"):
      j = j + "M"
    elif(m == "C"):
      j = j + "L"
    
      
  return j

correct = 0
loading_string = "...loading..."
print(f"{text.LOADING}")
for letter in loading_string:
  sleep(0.02) # In seconds
  stdout.write(letter)
  stdout.flush()

sleep(2)

passA = ["L", "w", "L", "w", "!", "M"]

print("\n")

print(f"{text.HEADER}\t\t\t\t-----  Its Quiz Time! -----")

sleep(1)

question_1 = "Question\t| What is the correct syntax for a color command? \n\t\t\t| a) colour(red) \n\t\t\t| b) color(red) \n\t\t\t| c) color('red') \n\t\t\t| (Write the letter of the sentence you think is correct)"
print(f"{text.QUESTION}")
count = 0
for letter in question_1:
  count += 1
  if (count > 11):
    sleep(0.1) # In seconds
    stdout.write(letter)
    stdout.flush()
  elif (count == 11):
    sleep(0.0001)
    stdout.write(letter)
    stdout.flush()
  else:
    stdout.write(letter)
    stdout.flush()

print("")
ans = input(f"{text.NEUTRAL}Answer\t\t| {text.NEUTRAL}")
print("\n")
if ((check(ans) == passA[0]) | (check(ans) == passA[1])):
  correct += 1
  print(f"{text.OKGREEN}Response\t| Yes, that's correct! This command will change the color\n\t\t\t| to red.\n")
else:
  print(f"{text.FAIL}Response\t| The correct answer was \"color('red')\".\n\t\t\t| Option \'a\' was spelt incorrectly and option \'b\' did\n\t\t\t| not have quotations around \"red\".\n")
  
sleep(3)

question_2 = "Question\t| To turn the turtle left, we can use: \n\t\t\t| a) west() \n\t\t\t| b) turtle.move.left() \n\t\t\t| c) left() \n\t\t\t| (Write the letter of the sentence you think is correct)"
print(f"{text.QUESTION}")
count = 0
for letter in question_2:
  count += 1
  if (count > 11):
    sleep(0.05) # In seconds
    stdout.write(letter)
    stdout.flush()
  elif (count == 11):
    sleep(0.1)
    stdout.write(letter)
    stdout.flush()
  else:
    stdout.write(letter)
    stdout.flush()

print()
ans = input(f"{text.NEUTRAL}Answer\t\t| {text.NEUTRAL}")
print("\n")

if (((check(ans) == passA[2]) | (check(ans) == passA[3])) & (correct == 1)):
  correct += 1
  print(f"{text.OKGREEN}Response\t| Another one correct! \n\t\t\t| Well done!\n")
elif (((check(ans) == passA[2]) | (check(ans) == passA[3])) & (correct == 0)):
  correct += 1
  print(f"{text.OKGREEN}Response\t| Great job, that's correct! \n")
else:
  print(f"{text.FAIL}Response\t| To turn left, we can use the \"left()\" command.\n")

sleep(3)

question_3 = "Question\t| What does the command \"forward(30)\" do?\n\t\t\t| a) Moves the turtle forward 30 units.\n\t\t\t| b) Tells the turtle there is something 30 units\n\t\t\t| in front of it.\n\t\t\t| c) Counts up from 0 until 30 until the turtle moves.\n\t\t\t| (Write the letter of the sentence you think is correct)"
print(f"{text.QUESTION}")
count = 0
for letter in question_3:
  count += 1
  if (count > 11):
    sleep(0.05) # In seconds
    stdout.write(letter)
    stdout.flush()
  elif (count == 11):
    sleep(0.1)
    stdout.write(letter)
    stdout.flush()
  else:
    stdout.write(letter)
    stdout.flush()

print()
ans = input(f"{text.NEUTRAL}Answer\t\t| {text.NEUTRAL}")
print("\n")

if (((check(ans) == passA[4]) | ((check(ans) == passA[5]))) & (correct == 2)):
  correct += 1
  print(f"{text.OKGREEN}Response\t| Wow, you got all of them correct! \n\t\t\t| Really well done!\n")
elif (((check(ans) == passA[4]) | ((check(ans) == passA[5]))) & (correct == 1)):
  correct += 1
  print(f"{text.OKGREEN}Response\t| Nice work! You got 2/3 which is superb and\n\t\t\t| you coded today! Great work!\n")

elif (((check(ans) == passA[4]) | ((check(ans) == passA[5]))) & (correct == 0)):
  correct += 1
  print(f"{text.OKGREEN}Response\t| Nice job! Not only did you code today, but you\n\t\t\t| got 1/3 which means that you learnt something!\n")
else:
  print(f"{text.FAIL}Response\t| The command \"forward(30)\" moves the turtle 30 units forward.\n\t\t\t| Great job coding today!")
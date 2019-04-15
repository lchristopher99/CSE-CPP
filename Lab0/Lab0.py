def main(): 
  getAverage('list.txt')
  printXWord()
  printLastXWord()

# opens list file and returns an indexed list of inventory including item name and amount
def getAverage(file_name):
  open_file = list(open(file_name, 'r'))
  total = 0
  i = 0

  # takes list from above, calculates, and prints the average
  while i < len(open_file):
    inventory_item = open_file[i].split(' ')
    total += int(inventory_item[1])
    i += 1

  average = total / len(open_file)
  print('First Part of Lab:')
  print('Average of Inventory List:', average)
  print()
# output = 'Average of Inventory List: 27.3'

# prints the first x amount of letters of inputted word or phrase
def printXWord():
  print('Second Part of Lab:')
  str = input('Please Input a Word or Phrase: ')
  x = int(input('Please Input Number a Characters to Print: '))

  print(str[0:x])
  print()
# if str = hello and x = 3, then output = 'hel'

# prints the last x amount of letters of inputted word or phrase
def printLastXWord():
  print('Third Part of Lab:')
  str = input('Please Input a Word or Phrase: ')
  x = int(input('Please Input Number a Characters to Print: '))

  print(str[-x:])
  print()
# if str = hello and x = 3, then output = 'llo'

if __name__ == "__main__":
  main()
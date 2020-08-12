class Animal():
  def __init__(self, c, n):
    self.creature = c
    self.name = n
    
  def get_creature(self ):
    return self.creature

  def get_name(self):
    return self.name
    
animals = []

animals.append(Animal("Dog", "Fido"))
animals.append(Animal("Cat", "Claws"))
animals.append(Animal("Mouse","Nibbles"))

for animal in animals:
  name = animal.get_name()
  creature = animal.get_creature()
  print(name + " is a " + creature)
from sympy import *
from sympy.logic.boolalg import truth_table

def somer(x):    
    final = str(simplify_logic(x,'cnf'))
    novos = {
      "~": "!",
      "&": "*",
      "|": "+",
    } 

    new = ''.join(novos.get(c, c)for c in final)
    mano = str(new)
    return mano
  

def truth(x,max):
  A,B,C,D = symbols('A,B,C,D')
  if max == 4:
    truth = truth_table(x,[A,B,C,D],true)
    print ("A - B - C - D")
  if max == 3:
    truth = truth_table(x,[A,B,C],true)
    print ("A - B - C")
  if max == 2:
    truth = truth_table(x,[A,B],true)
    
  for t in truth:
      print('{0} -> {1}'.format(*t))
      
def sop(x):    
    final = str(simplify_logic(x,'dnf'))
    novos = {
      "~": "!",
      "&": "*",
      "|": "+",
    } 

    new = ''.join(novos.get(c, c)for c in final)
    mano = str(new)
    return mano
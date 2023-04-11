

input:
    atom type
    atom mass
    residue type
    PWM matrix(split by residue)
    2rd structure
    disordered
    ...
    
atoms graph(fully connected graph)：
  node: atom
  node feature: 
    atom type
    atom mass
  edge: full connected
    
residues graph(fully connected graph):
  node: residue
  node feature:
    residue type
    PWM matrix(split by residue)
    2rd structure
    disordered
    ...
  edge: full connected
  
interaction:
  residue node to residue node within residues graph
  atom node to atom node within atoms graph
  residue node to atom node between atoms graph and residues graph
  atom node to residue node between atoms graph and residues graph
  ==> get residue high level feature

option1: train sequence and residue info data ==> predict PRI
option2: train sequence ==> predict residue info data
         get pretrained sequence based model ==> predict PRI
option3: with or without atoms graph
option4: train sequence ==> predict structure info
         get pretrained sequence based model ==> predict PRI



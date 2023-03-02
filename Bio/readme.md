## terminology

### what is Gibbs free energy?
To explore the dynamic properties behind mutations, molecular dynamic (MD) simulations have been widely performed, especially in unveiling the mechanism of drug failure behind mutation. When comparing wild type (WT) and mutants (MTs), the structural changes along with solvation free energy (SFE), and Gibbs free energy (GFE) are calculated after the MD simulation, to measure the effect of mutations on protein structure.


### MMseqs2 software
used to find the “similar proteins”

### SCOP
The classification of the proteins in SCOP is on hierarchical levels as follows:

Family. Proteins are clustered together into families on the basis of one of two criteria that imply their having a common evolutionary origin: first, all proteins that have residue identities of 30% and greater; second, proteins with lower sequence identities but whose functions and structures are very similar; for example, globins with sequence identities of 15%.

Superfamily. Families whose proteins have low sequence identities but whose structures and, in many cases, functional features suggest that a common evolutionary origin is probable, are placed together in superfamilies; for example, the variable and constant domains of immunoglobulins.

Common fold. Superfamilies and families are defined as having a common fold if their proteins have the same major secondary structures in the same arrangement and with the same topological connections. The structural similarities of proteins in the same fold category probably arise from the physics and chemistry of proteins favouring certain packing arrangements and chain topologies.

Class. The different folds have been grouped into classes. Most of the folds are assigned to one of the five structural classes:

1. all-α, those whose structure is essentially formed by α-helices;

2. all-β, those whose structure is essentially formed by β-sheets;

3. α/β, those with α-helices and β-strands;

4. α+β, those in which α-helices and β-strands are largely segregated;

5. multi-domain, those with domains of different fold and for which no homologues are known at present.

Other classes have been assigned for peptides, small proteins, theoretical models, nucleic acids and carbohydrates.

There are now a number of other databases which classify protein structures, such as CATH (4), FSSP (5), Entrez (6) and DDBASE (7), however, the distinction between evolutionary relationships and those that arise from the physics and chemistry of proteins is a feature that is so far unique to SCOP. Because functional similarity is implied by an evolutionary relationship but not necessarily by a physical relationship, we believe that this classification level is of considerable value, for example as a way of reliably linking very distant sequence families.


PremPS: valuate the effects of missense mutations on protein stability.

### Protein-protein interactions
Protein-protein interactions (PPIs) are involved in many cellular processes. Experimentally obtained protein quaternary structures provide the location of protein-protein interfaces, the surface region of a given protein that interacts with another. These regions are termed half-interfaces (HIs).
Knowing the HIs involved in protein-protein interactions can greatly assist in determining the interaction pose of two proteins. According to currently available solved structures of multimeric complexes, on average, approximately one third of a protein’s surface is known to form an interface in quaternary complexes. Thus, protein-protein interfaces were viewed as being special, and many efforts were made to predict these surface regions.

### MutaBind2: 
disease mutations and found that many of them were located on protein-binding interfaces
to calculate the changes in binding affinity induced by mutations
### MutaBind:
assess the effects of cancer mutations on binding between CBL ubiquitin ligase and E2 conjugating enzyme

### Cbl
(named after Casitas B-lineage Lymphoma) is a mammalian gene encoding the protein CBL which is an E3 ubiquitin-protein ligase involved in cell signalling and protein ubiquitination. 
### ubiquitin ligase 
A ubiquitin ligase (also called an E3 ubiquitin ligase) is a protein that recruits an E2 ubiquitin-conjugating enzyme that has been loaded with ubiquitin, recognizes a protein substrate, and assists or directly catalyzes the transfer of ubiquitin from the E2 to the protein substrate. In simple and more general terms, the ligase enables movement of ubiquitin from a ubiquitin carrier to another thing (the substrate) by some mechanism. 
### cell signaling
In biology, cell signaling (cell signalling in British English) or cell communication is the ability of a cell to receive, process, and transmit signals with its environment and with itself


## evaluation

### Matthew’s correlation coefficient formula
MCC is a best single-value classification metric which helps to summarize the confusion matrix or an error matrix. 


typedef struct tnode *Treeptr;

typedef struct tnode {
    char *word;
    int count;
    Treeptr left;
    Treeptr right;
} Treenode;

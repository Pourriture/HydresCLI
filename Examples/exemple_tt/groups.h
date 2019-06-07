#ifndef GROUPS_H_INCLUDED
#define GROUPS_H_INCLUDED

typedef struct groupe groupe;

struct groupe
{
    long ID;
    unsigned int effectif;
    UV_def *choixUV[7];
};


#endif // GROUPS_H_INCLUDED

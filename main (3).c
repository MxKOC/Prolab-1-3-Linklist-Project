#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

struct n{
    int x;
    char c[30];
    struct n *next;
};
typedef struct n node;



//////////////////////////////////////////////////////////////////////////

int say(node*r,char *zz,int yy){





node * say;
say=r;



    int sayac = 0;

    while(say != NULL)
    {

        if(strcmp(say->c,zz) == 0)
        {

            sayac = 1;
            break;

        }
        say = say->next;
    }

    return sayac;


}

///////////////////////////////////////////////////////////////////////















void goster(node *r){

    while(r!=NULL){
        printf("%s --> %d adet\n",r->c,r->x);
        r=r->next;
    }
}

node *basaEkle(node *r,char *c,int x){




    node *tmp = (node *)malloc(sizeof(node));
    strcpy(tmp->c,c);
    tmp->x = x;
    tmp->next = r;
    r = tmp;
    return r;
}

node *sonaEkle(node *r,char *c,int x){
    node *iter = r;
    while(iter->next != NULL){
        iter = iter->next;
    }

    node *tmp = (node *)malloc(sizeof(node));
    strcpy(tmp->c,c);
    tmp->x = x;
    tmp->next = NULL;
    iter->next = tmp;
    return r;

}

node *arayaEkle(node *r,char *c,int x){
    node *iter =r;
    while(iter->next->x > x)
        iter = iter->next;
    node *tmp = (node *)malloc(sizeof(node));
    strcpy(tmp->c,c);
    tmp->x = x;
    tmp->next = iter->next;
    iter->next = tmp;
    return r;


}

node *eklemeler(node *r,char *c,int x){


    if(r == NULL){
        r = (node*)malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        strcpy(r->c,c);
        return r;
    }

    node *iter;
    iter = r;

    if(say(r,c,x)==1){return r;}




    //////////////////////////////////////////////////




    if(r->x <= x){
        r = basaEkle(r,c,x);
        return r;
    }
    iter = r;
    while(iter->next != NULL)
          iter = iter->next;
    if(iter->x >= x){
        r = sonaEkle(r,c,x);
        return r;
    }

    r = arayaEkle(r,c,x);
    return r;
}


int main()
{
    setlocale(LC_ALL, "Turkish");

    FILE *dosya;
    dosya=fopen("text.txt","r");
char *yer= (char*) malloc(100 * sizeof(char));
int saybosluk=0;

while(!feof(dosya)){
yer=getc(dosya);
if(yer==' ') {saybosluk++;}
if(yer=='\n'){saybosluk++;}
}
fclose(dosya);
printf("%d",saybosluk);


////////////////////////////////////////////////////////////////////////
    node *r = NULL;

char *yer2= (char*) malloc(100 * sizeof(char));
char *yer3= (char*) malloc(100 * sizeof(char));
FILE *dosya2;
FILE *dosya3;
int say3say=0;
(dosya2=fopen("text.txt","r+"));
for(int i=0;i<saybosluk+1;i++){
fscanf(dosya2,"%s",yer2);
say3say=0;
(dosya3=fopen("text.txt","r+"));
for(int j=0;j<saybosluk+1;j++){
fscanf(dosya3,"%s",yer3);
if (strcmp(yer2,yer3));
//printf("i:%d - j:%d - 3:%s - 2:%s\n",i,j,yer3,yer2);
else {
        //printf("asd i:%d - j:%d - 3:%s - 2:%s\n",i,j,yer3,yer2);
say3say++;}
}
//printf("---------%d",say3say);
fclose(dosya3);
r=eklemeler(r,yer2,say3say);
}
/////////////////////////////////////////////////////////////////

goster(r);



    FILE *son;

if((son=fopen("sonuc.txt","w")) != NULL){
while(r!=NULL){
        fprintf(son,"%s->%d\n",r->c,r->x);
        r=r->next;
    }


}



else{
    printf("olmadi");
}
fclose(son);




    return 0;
}

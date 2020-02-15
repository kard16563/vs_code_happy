# include <stdio.h>
# include <stdlib.h>


typedef struct tree{

    int data;
    struct tree *left,*right;

}tree ,*tree_node;


void check(tree_node pp,int p){//前驱遍历

    if ((pp->data) >0){
        printf(" a value  --->  %d  positon %d ---  %d \n" ,pp->data,p,pp);
        //printf(" b  value  --->  %d  positon %d ---  %d \n" ,pp->left,p,pp->left);
        //if((pp->right) )printf("nononon");

	check(pp->left,1);
    check(pp->right,2);
    }
    }


void creat_tree( tree_node pp ,int cc ){
    tree_node tt=pp;

    printf("  state -->> %d    pos %d %d \n",cc,pp,tt);

    int ch;
    scanf("%d",&ch);
    getchar();

    printf("---> %d  \n",ch);

    if (ch == -1){
        pp->data=-1;
        pp->left=NULL;
        pp->right=NULL;
        printf("  captuere the space  creat will quit!! ");
        }
    else{
        //if (!( pp = (tree_node)malloc(sizeof (tree)) )) {
        //  printf("  error!! \n ");
        // exit(0);
        //}else{

        printf(" ok  well -- new posi %d \n",pp);
//}
        pp->data=ch;
        printf(" ====> center->%d  pos %d\n\n",pp->data,pp);
        creat_tree(pp->left = (tree_node)malloc(sizeof (tree)),1);//防止指针丢失
        creat_tree(pp->right = (tree_node)malloc(sizeof (tree)) ,2);
        
        //printf("==== check_self ==== %d \n\n",tt);
        //check(tt,0);
        }
        printf("\n\n  has quited!!  \n\n");




}









int main(){
tree pp;
creat_tree(&pp,0);
printf("\n\n     checking------>\n\n");
check(&pp,0);


//tree_node tt;
//tt= (tree_node)malloc(sizeof (tree));
//tt= NULL;
//printf("   %d   \n\n",tt);
//printf("   %d , %d  \n\n",tt,tt->right); //不行的原因


//goto end;//跳转 想实现一个try  catch 

//int a=2000;

//if (tt->left){
//	printf("123");
	
	//sleep(a);
	//goto end;

//}else{

//printf("456");

//}

//end:
	printf("\n\n\n123456\n\n");
    getchar();
    getchar();
    return 0;


}
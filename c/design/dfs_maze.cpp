#include <stdio.h>
#include <stdlib.h>

int maze[9][9] =
    {  //0  1  2  3  4  5  6  7  8
        {0, 1, 1, 1, 1, 1, 1, 1, 1}, //0
        {1, 0, 0, 1, 0, 0, 1, 0, 1}, //1
        {1, 0, 0, 1, 1, 0, 0, 0, 1}, //2
        {1, 0, 1, 0, 1, 1, 0, 1, 1}, //3
        {1, 0, 0, 0, 0, 1, 0, 0, 1}, //4
        {1, 1, 0, 1, 0, 1, 0, 0, 1}, //5
        {1, 1, 0, 1, 0, 1, 0, 0, 1}, //6
        {1, 1, 0, 1, 0, 0, 0, 0, 1}, //7
        {1, 1, 1, 1, 1, 1, 1, 1, 1}, //8
};

typedef struct loop_cut
{
    int row;
    int col;
    struct loop_cut *next;

} loop_cut_, *loop_cut_node;

loop_cut_ loop_cut[9];

void check_point(int cc[], int posi)
{
    cc[posi] = 1;
    printf("\n  position add---> %d \n", posi);

    //return cc[posi];
}

void init_loop_cut_(loop_cut_ loop_cut[], int num)
{
    printf("  >>  enter  func init_loop_cut_  **************\n");
    for (int i = 0; i < num; i = i + 1)
    {
        printf(" \n >> >>  init_loop_cut_ _->for->\
 before change --> the row is %d---->  next : %p   index : %d  \n", \
                                loop_cut[i].row, loop_cut[i].next, i);

        loop_cut[i].row = -1;
        printf("\n >> >>  init_loop_cut_ _->for->after change --> \
 the row is %d ----->  index : %d  \n\n\n", loop_cut[i].row, i);
    }

    printf(" \n\n\n func_init_loop_cut_ is end \n\n  ");
}

void cut_loop(loop_cut_ loop_cut[], int news, int old)
{ // maze[start 1 ][i 0]  --> maze,i,start
    printf("\n\n\n ===>  enter func cut_loop ******** \n \n");
    printf("\n >> func_cut_loop-> news_i %d old_start %d   \n ", news, old);

    loop_cut_node nod = &loop_cut[news];
    printf("  >> func_ loop_cut_  ->   original nod  --> row:  %d  \
next: %p,add-> %d", nod->row, nod->next, old);

    if (nod->row != -1) //  can not  add 
    {                   // has value
       int still_have=0;
        while (nod->row != -1  )
        {
            printf("\n>> >> >> func_ loop_cut_  >>  if(has value == nod->row != -1 ) >> while(to find the nod without walue == nod->row != -1 ) ->>fuc_ cut_loop  nod->row: %d ", nod->row);
            
            if(nod->row==news && nod->col == old ){
                still_have=1;
            }

            nod = nod->next;
            //loop_cut[news] = loop_cut[news].next;----->
            
        }
        if(still_have==0){
        printf("\n>> >> >> >>  func_ loop_cut_  >>\n    \
if(has value == nod->row != -1 ) >>while(to find the nod without \
walue == nod->row != -1 )\n >>after \
the while1 find the value nod->row : \
%d  ", nod->row);
        

        nod->col = old; // index
        nod->row = news;

        printf("\n >> >> >> >>  func_ loop_cut_  >>\n    \
if(has value == nod->row != -1 ) >>while(to find the nod without \
walue == nod->row != -1 )\n>>after the while1 find the value nod >> \
add record col-> %d row-> %d  \n\n ", \
nod->col, nod->row);

        nod->next = (loop_cut_node)malloc(sizeof(loop_cut_));
        nod->next->row = -1;
        }
    }
    else
    {

        nod->col = old; // index
        nod->row = news;
        nod->next = (loop_cut_node)malloc(sizeof(loop_cut_));
        nod->next->row = -1;
         printf("\n> func: _cut_loop  add record col-> %d row-> %d  next:%p \
next value:%d \n\n ",nod->col,nod->row ,nod->next,nod->next->row);
        //loop_cut[news].next->row=-1;
    }
}

int dfs_test(int maze[][9], int start, int old)
{ // maze[start][i]  --> maze,i,start
    int isloop=0;
    printf("\n\n\n      ===> enter  dfs test fuction ***** \n\n");
    for (int i = 0; i < 9; i = i + 1)
    {

        printf("\n >> >> func_dfs_test_->for ->>  find this time: (index)i: %d  start: %d  old: %d   maze[start][i] : %d \n",i, start, old, maze[start][i]);
        //printf("\n  ---->>%d\n",maze[start][i]);
        if (i == old)
        {
            //return
            printf("\n >> >> >> func_dfs_test_->for_->if(i==old)->   \
dfs_test the answer:  ___ loop!! __ i(col):%d  row(start) : %d\n",\
                                                     i, start);
            cut_loop(loop_cut, start, old);
            printf("\n\n\n      cut_loop is end ---------> \n");
            isloop=1;

            //return i, start;
        }
        else
        {
            printf("\n>> >> >> func_dfs_test_->for_->if(i==old)->   \
dfs_test the answer: no loop !!!\n");
            //dfs_test(maze,start,old);//problem
        }
    }

    
    //return 0;//---->cut the 迭代  return some things
    if(isloop == 1 ){
        printf("\n\n\n      func_dfs_test is end !! isloop: %d --------->\n\n",isloop);
        return isloop;

    }else
    {
        printf("\n\n\n      func_dfs_test is end !! isloop: %d ---------> \n\n",isloop);
        return isloop;
    }
    

    
}

int isloop(int maze[][9], int start, int old)
{ // maze[start][i]  --> maze,i,start
    // start ---> jump back to the old, old----> new
    printf("\n\n\       ===> enter is loop fuction  check the loop\
__old row: %d ___  new %d ***** \n\n", old, start);

    //printf("..");
    int ans=dfs_test(maze, start, old);
    printf(" \n\n\n     isloop_ function  is end-------->return(isloop) : %d \n  ",ans);
    return ans;
}

void jump_check(loop_cut_ loop_cut[],int i){
    printf("\n\n\n      ===> enter the func_jump_check ****** loop_cut[i=%d] next : %d  next->row :%d \n\n",i,loop_cut[i].next,loop_cut[i].next->row);
    printf("\n >> func_jump_check -> this loop_cut[i].row : %d ,loop_cut[i].col: %d \n",loop_cut[i].row,loop_cut[i].col);
    loop_cut_node nod = loop_cut[i].next;
    while (nod->row !=-1  ){
        printf("\n>> >> fun_ jump_check _> while ->  row : %d  nod: %d \n",nod->row,nod->col);
        nod=nod->next;
    }
    printf("\n\n\n      func_jump_check is end ------>\n");


}



int dfs(int maze[][9], int start, int end, int flag, int cc[], int i)
{
    //printf("\n\n  >> func_dfs __%d \n\n",start);
    flag = flag + 1;

    printf("\n\n>> func_dfs  start %d ----flag\
(iteration迭代times )  %d------ end %d i:%d \n ", start, flag, end,i);
    printf("\n\n enter?----------------->>> ");
    int a;
    scanf("%d",&a);//easy to check

    for ( i; i < 9; i = i + 1)
    {
        

        printf(">> >> func_dfs_->for  \
start  %d  __- (i)index  %d \n", start, i);
        
        printf(">> >> func_dfs_->for   find this time- \
the value maze[start][i] :--->  %d  \n", maze[start][i]);

        if (maze[start][i] == 1)
        { //have the way
        int ans_from_isloop=0;

            printf("\n>> >> >> func_dfs_->for_->\
(if have the way ) judge have the way \
---->  value: %d  maze[start][i] --> start - %d   i - %d  \n",maze[start][i], start, i);
            //printf("have the way____ ---->s %d  i--- %d",start,i);

            if (i < start || i == start)
            {
                printf("\n>> >> >> >> func_dfs_-> \
for_-> (if have the way ) judge have the way _-> \n   judge(is loop by\
(i<start || i == start)  )  ->  isloop()____>>\n");

                ans_from_isloop= isloop(maze, i, start); //i--> The last generation
                // this generation
                printf("\n\n\n>> >> >> >>  end isloop (maze,i,start)\
back to func_ dfs return %d------>>>\n\n",ans_from_isloop);
            }else
            {
                printf("\n>> >> >> >> func_dfs_->\
for_-> (if have the way ) judge have the way _-> \n   judge(is loop by\
(i<start || i == start)  )  ->  no!!! \n");
            }
            

            if(ans_from_isloop == 1){

                printf("\n >> >> >> >> func_dfs _-> \
for _-> (if have the way ) judge have the way _-> afterloop()_> \
if（ans_from_isloop） ->  yes \n");

                //dfs(maze, start, end, flag, cc, i+1);//jump
                // 发现之后跳开 前面的回来的点 然后在前面进行遍历
                jump_check(loop_cut,i);
                dfs(maze, start=i, end, flag, cc, 0);
                

            }
            else
            {
                printf("\n>> >> >> >> func_dfs_-> \
for_-> (if have the way ) judge have the way _->  afterloop()_> \
if（ans_from_isloop） ->  no \n");

                dfs(maze, i, end, flag, cc, 0);
            }
        }
        else
        {// jump to next has way

            i = i + 1;
            printf("\n >> >> >> >> func_dfs_->\
for_->(if have the way ) -> jump to have way %d \n",i);
            dfs(maze, start, end, flag, cc, i);
        }

        // if (!cc[i]){
        //     check_point(cc,start);//add point
        // }
        // printf("\n\n ==== next >in--> %d ---> this state %d",i,cc[i]);
        // if (!cc[i]){
        //         printf("\n\n =====----- new rows ----====== \n");
        //         dfs(maze,i,end,flag,cc);
        //         printf(" out-->");
        //         if (start == end){
        //             printf("\n***************catch----->>>>");
        return 1;
        //                 }
        // }
    }
}

int main()
{
    int cc[9] = {0};
    init_loop_cut_(loop_cut, 9);
    dfs(maze, 0, 2, 0, cc, 0);

    printf("\n \n endding------------------------->");
    getchar();
    getchar();

    return 0;
}

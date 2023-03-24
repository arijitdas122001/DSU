#include<iostream>
using namespace std;
class queue{
    public:
    int size,b,r;
    int *arr;
};
int isfull(queue *q){
    if(q->r== q->size-1){
return 1;
    }
    return 0;
}
int isempty(queue *q){
    if (q->r==q->b) 
    {
        return 1;
    }
    return 0;
}
void enqueue(queue *q,int val){
    if (isfull(q))
    {
       cout<<"Queue overloded"<<endl;
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
       cout<<"Enqueue element"<<val<<endl;
    }
}
int dequeue(queue *q){
    int a=-1;
    if (isempty(q))
    {
        cout<<"There is nothing to delete"<<endl;
    }
    else{
q->b++;
a=q->arr[q->b];
    }
    return a;
}
int main(){
class queue *q=new queue();
q->b=-1;
q->r=-1;
q->size=10;
q->arr=new int();
enqueue(q,12);
enqueue(q,42);
enqueue(q,22);
enqueue(q,2);
cout<<"Dequeiing element"<<dequeue(q);
enqueue(q,94);
return 0;
}
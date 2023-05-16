#include <stdio.h>
#include <iostream>
#include <string.h>
#define NMAX 100

using namespace std;
template<typename T> class Queue {
    private:
        T queueArray[NMAX];
        int head, tail;
    public:
        int getTail(){
          return this->tail;
        }

        T get(int i){
          return this->queueArray[i];
        }

        int getHead(){
          return this->head;
        }
        void enqueue(T x) {
            if (tail == NMAX) { //we check if the queue is full
                cout<<"Error 101 - The queue is full!\n";
                return;
            }
            queueArray[tail] = x; //we add the element at the end of the queue
            tail++; //we shift the tail to the right
        }

        T dequeue() {
            if (isEmpty()) { //we check if the queue is empty
                cout<<"Error 102 - The queue is empty!\n";
                T x;
                return x;
            }
            T x = queueArray[head]; //we return the element situated at the head
            head++;                          //we shift the head to the right
            return x;   }

        T dequeueHighestPriority(){
          if (isEmpty()){
            std::cout << "Queue is emplty!" << '\n';
            T x;
            return x;
          }else{
          T om;
          om.val = 0;
          int max = 0;
          int k;
          for(int i = head; i < tail-1 ; i++)
            if (max < queueArray[i].nr){
              max = queueArray[i].nr;
              om = queueArray[i];
              k = i;
            }
          for(int i = k; i < tail; i++){
            queueArray[i] = queueArray[i+1];
           }
          tail--;
          if (om.val != 0)
            return om;
          else{
            om.nr = 0;
            return om;
          }
          }
        }

        T getHighestPriority(){
          if (isEmpty()){
            std::cout << "Queue is emplty!" << '\n';
            T x;
            return x;
          }else{
          T om;
          om.val = 0;
          int max = 0;
          int k;
          for(int i = head; i < tail-1 ; i++)
            if (max < queueArray[i].nr){
              max = queueArray[i].nr;
              om = queueArray[i];
              k = i;
            }
          if (om.val != 0)
            return om;
          else{
            om.nr = 0;
            return om;
          }
        }
      }

        T peek() {
            if (isEmpty()) {//we check if the queue is empty
                cout<<"Error 103 - The queue is empty!\n";
                T x;
                return x;
            }
            return queueArray[head]; //we return the element situated at the head
        }

        int isEmpty() {
            return (head == tail); //if head and tail are equal, the queue is empty
        }

        void display(){
          for(int i = head; i < tail; i++)
            std::cout << queueArray[i].val << " " << queueArray[i].nr << " " << queueArray[i].code << '\n';
        }

    Queue() {
        head = tail = 0; // the queue is empty at the beginning
    }
};

int contains(char s[], char x){
  if (x == ' ') return 1;
  for (int i = 0; i < strlen(s); i++){
    if (s[i] == x)
      return 1;
  }
  return 0;
}

void DecToBin(char *arr, int nr){
  int i = 0;
  char x[32];
  if (nr == 0)
    x[0] = '0';
  else{
    while(nr != 0){
      if(nr % 2 == 0)
        x[i] = '0';
      else
        x[i] = '1';
      nr /= 2;
      i++;
    }
  }
  for(int j = 0; j < i;j++)
    arr[j] = x[i-1-j];
}

int getOnes(char ar[]){
  int count = 0;
  for(int i = 0; i < strlen(ar); i++)
    if(ar[i] == '1')
      count++;
  return count;
}

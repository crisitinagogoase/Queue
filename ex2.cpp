#include "header.h"

struct t{
  public:
    char val;
    int nr;
    char code[32] = "";

};

int main(){
  char str[150] = "Tous les mythes sont les fondamentes de la réalité. Il suffit de continuer à les compter.";
  t om;
  Queue<t> liste;
  int j;
  t ls[50];

  for(int i = 0; i < strlen(str); i++)
    if(str[i] >= 'A' && str[i] <= 'Z')
      str[i] = ((int)str[i] + 32);
  std::cout << str << '\n';
  char smn[50] = "";
  int x = -1;
  for(int i = 0; i < strlen(str); i++){
    int count = 0;
    j = i;
    char c = str[j];
    if(!contains(smn, c)){
      for(;j < strlen(str); j++)
        if((str[j] == c) && (str[j] != ' '))
          count++;
      smn[++x] = c;
      om.val = c;
      om.nr = count;
      ls[x] = om;
      liste.enqueue(om);
    }
  }
  liste.display();
  std::cout << " message " << liste.getHighestPriority().val << " " <<liste.getHighestPriority().nr << '\n';

  Queue<t> l1;
  j = 0;

  while(!liste.isEmpty()){
    om = liste.getHighestPriority();
    DecToBin(om.code, j);
    l1.enqueue(om);
    liste.dequeueHighestPriority();
    j++;
  }

  int k = 0;
  std::cout << "/* message */" << '\n';
  for(j = 0; j < strlen(str); j++){
    while(str[j] == ' '){
      std::cout << ' ';
      j++;
    }
    for(int i = l1.getHead(); i < l1.getTail(); i++){
      if (l1.get(i).val == str[j]){
        k += getOnes(l1.get(i).code);
        std::cout << l1.get(i).code;
        break;
      }
    }
  }
  std::cout << " code: " << k << '\n';

  //l1.display();

  /*
  for(int i = 0; i < x ; i++)
    for(int j = i + 1; j <= x; j++){
      if(ls[i].nr < ls[j].nr){
        om = ls[i];
        ls[i] = ls[j];
        ls[j] = om;
      }
    }
  */

  /*
  std::cout << "|adasdadada|" << '\n';
  for(int i = 0; i <= x; i++)
    std::cout << ls[i].nr << '\n';
    */
}

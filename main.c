#include <stdio.h>
#include <stdlib.h>


int authenticate(int pin){
    if (pin == 1974){
        return 1;
    }else{
        return 0;
    }
}

float balance = 1e+6;

float requestAmount(void){
    float amount;
    printf("Enter amount: ");
    scanf("%f",&amount);
    return amount;
}

void deposit(float amount){
    balance +=amount;
    printf("Deposit successfully. New balance: %g\n",balance);
}

void withdraw(float amount){
    if(balance < amount){
        printf("Insufficient balance\n");
    }else{
        balance -= amount;
        printf("Withdrawal successful. New balance: %g\n", balance);
    }
}

void transfer(float amount){
    int receiptAccountNumber;
    printf("Enter recipient account number: ");
    scanf("%d",&receiptAccountNumber);
    if (balance < amount) {
        printf("Insufficient balance\n");
    } else {
        balance -= amount;
        printf("Transfer successful. New balance: %g\n", balance);
    }
}

int main(){
    start:
    printf("WELCOME TO CYRIL'S BANK\nEnter your four digit pin: ");
    int tries = 0;
    int pin=0;
    scanf("%d", &pin);
    menu:
    if(authenticate(pin) && tries < 4){
        int menu_item;
        printf("Select an option\n1. Check Balance\n2. Withdrawal\n3. Deposit\n4. Transfer\n");
        scanf("%d", &menu_item);
        switch(menu_item){
            case 1: printf("Balance: %g\n", balance);
                    break;
            case 2: withdraw(requestAmount());
                    break;
            case 3: deposit(requestAmount());
                    break;
            case 4: transfer(requestAmount());
                    break;
            default: printf("Invalid option selected.\n");
                     break;
        }
    } else{
        ++tries;
        printf("Invalid pin after %d tries\n", tries);
        if (tries == 4) {
            printf("Maximum number of tries exceeded. Account blocked.\n");
            return 0;
        }else
        goto start;
    }
    int response;
    printf("Would you like to perform another transaction?\n1. Yes\n2. No\n");
    scanf("%d", &response);
    if(response == 1){goto menu;}


    printf("Thank you for banking with us.\n");
    return 0;
}


/*int authenticate(int pin){
    if (pin == 1974){
        return 1;
    }else{
        return 0;
    }
}
float balance = 1e+6;

int requestAmount(void){
float amount;
printf("Enter amount: ");
scanf("%f",&amount);
return amount;
}

void deposit(float amount){
    balance +=amount;
    printf("Deposit successfully. New balance: %g\n",balance);
}

 void withdraw(float amount){
     if(balance < amount){
        printf("Insufficient balance\n");
     }else{
         balance -= amount;
         printf("Withdrawal successful. New balance : %g \n", balance);
     }
 }

 void transfer(float amount){
     int receiptAccountNumber;
     printf("Enter receiptient account number :");
     scanf("%d",&receiptAccountNumber);
     {
          if (balance < amount) {
        printf("Insufficient balance\n");
    } else {
        balance -= amount;
        printf("Transfer successful. New balance; %g\n", balance);
    }

 }


int main(){
  start:
  printf("WELCOME TO ABC BANK\nEnter your four digit pin\n");
  int tries = 0;
  int pin=0;
  scanf("%d", &pin);
  menu:
   if(authenticate(pin) && tries < 4){
    int menu_item;
  printf("Select an option\n1. Check Balance\n2. Withdrawal\n 3.Deposit\n4. Transfer\n");
 scanf("%d", &menu_item);
 switch(menu_item){
 case 1: printf("%g\n", balance);
 break;
 case 2: withDraw(requestAmount());
 break;
 case 3: deposit(amount);
 break;
 case 4: transfer(amount);
 }
 }
 else{
 ++tries;
 printf("Invalid pin after %d tries\n", tries);
 goto start;
 }
 int response;
 printf("Would you like to perform another transaction?\n1. Yes\n2.No\n");
 scanf("%d", &response);
 if(response == 1){goto menu;}

printf("Thank you for banking with us\n");
return 0;
}
 }
 */

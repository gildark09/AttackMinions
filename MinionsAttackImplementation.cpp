#include "MinionsAttack.h"

void print(char string[]){
	for(int i = 0; string[i] != '\0'; i++){
		printf("%c", string[i]);
		Sleep(0);
	}
}

void StartGame(){
	PLAYER player = {500, 0, {20, 0, 0, 0, 0}};
	int choice = 0;
	
	print("Welcome to Attack minions!\n");
	print("[1]Start Game\n");
	print("Choice: "); 
	scanf("%d", &choice);
	
	switch(choice){
		case 1: system("cls"); SoloGameplay(player);
	}
}

void printReturn(){
	print("Returning back to your Kingdom!\n");
	Sleep(2000);
	system("cls");
}

void printEnemyCastle(){
	gotoxy(95, 10);
	printf("          O   \n");
	gotoxy(95, 11);
    printf("         /|\\  \n");
    gotoxy(95, 12);
    printf("         / \\  \n");
    gotoxy(95, 13);
    printf("  ===================  \n");
    gotoxy(95, 14);
    printf("  | []  |  []  |  [] |\n");
    gotoxy(95, 15);
    printf("  |  [] |  []  | []  |\n");
    gotoxy(95, 16);
    printf("  |_____|______|_____|\n");
    gotoxy(95, 17);
    printf("  |      Castle      |\n");
    gotoxy(95, 18);
    printf("  |__________________|\n");
}

void printPlayerCastle(){
	printf("          O   \n");
    printf("         /|\\  ATTACK MINIONS!\n");
    printf("         / \\  \n");
    printf("  ===================  \n");
    printf("  | []  |  []  |  [] |\n");
    printf("  |  [] |  []  | []  |\n");
    printf("  |_____|______|_____|\n");
    printf("  |      CASTLE      |\n");
    printf("  |__________________|\n");
}

void printEnemySoldiers(ENEMY enemy){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	print("The enemy has: ");
	printf("%d\n", enemy.soldiers);
	print("soldiers!\n");
	SetConsoleTextAttribute(hConsole, 7);
	return;
}

PLAYER attack(PLAYER player){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	int input;
	int variation = 5;
	ENEMY enemy;
	int minSoldiers = player.army.soldiers - variation;
	int maxSoldiers = player.army.soldiers + variation;
	if(minSoldiers < 0) minSoldiers = 0;
	enemy.soldiers = minSoldiers + (rand() % (maxSoldiers - minSoldiers + 1));
	system("cls");
	print("Preparing for war please wait...\n");
	Sleep(2000);
	system("cls");
	
	SetConsoleTextAttribute(hConsole, 3);
	
	print("Before we start the attack you need to know how to arrange your soldiers first!\n");
	print("A quick way to arrange your soldiers is to input 2 numbers\n");
	print("the 1st number is for the length of your army\n");
	print("the 2nd number is for the width of your army\n");
	print("for example: 2 3\n");
	print("Output: \n");

	print("I I I\nI I I\n");
	SetConsoleTextAttribute(hConsole, 7);
	
	printEnemySoldiers(enemy);
	Sleep(1000);
	system("cls");
	
	do{
		
		if(player.army.soldiers <= 1){
			system("cls");
			gotoxy(35, 15);
	        print("You have no soldiers left. You lost the war...\n");
	        printReturn();
	        return player;
		}
		
		system("cls");
		SetConsoleTextAttribute(hConsole, 3);
		printf("Soldiers left: %d\n", player.army.soldiers);
		gotoxy(0, 10);
		printPlayerCastle();
		SetConsoleTextAttribute(hConsole, 7);
		
		SetConsoleTextAttribute(hConsole, 4);
		gotoxy(100, 0);
		printf("Soldiers left: %d\n", enemy.soldiers);
		printEnemyCastle();
		SetConsoleTextAttribute(hConsole, 7);
		
		print("\n\nHow many soldiers do you wanna send: ");
		scanf("%d", &input);
		
		if(input <= 0 || input > player.army.soldiers){
			print("You can't send that amount of troops my lord!\n");
			continue;
		} else {
			player.army.soldiers -= input;
			print("You will send ");
			printf("%d", input);
			print(" soldiers into the battlefied\n");
			char playerArmy[input];
			char arrangedArmy[player.army.row][player.army.col];
			for(int i = 0; i < input; i++){
					playerArmy[i] = 'I';
			}
			
			if(input == 1){
				int minEnemy = input - 2;
				int maxEnemy = input + 2;
				if (minEnemy < 1) minEnemy = 1;
				if (maxEnemy > enemy.soldiers) maxEnemy = enemy.soldiers;
				
				int enemySent = minEnemy + (rand() % (maxEnemy - minEnemy + 1));
				enemy.soldiers -= enemySent;
				char enemyArmy[enemySent];
				
				gotoxy(45, 15);
				printf("The enemy has sent %d Soldiers!\n", enemySent);
				
				player.army.x = 25;  
				player.army.y = 20;  
				enemy.x = 95;  
				enemy.y = 20; 
				
				for(int steps = 0; steps < 34; steps++){
					system("cls");  
					
					SetConsoleTextAttribute(hConsole, 3);
					printf("Soldiers left: %d\n", player.army.soldiers);
					gotoxy(0, 10);
					printPlayerCastle();
					SetConsoleTextAttribute(hConsole, 7);
					
					
					SetConsoleTextAttribute(hConsole, 4);
					gotoxy(100, 0);
					printf("Soldiers left: %d\n", enemy.soldiers);
					printEnemyCastle();
					SetConsoleTextAttribute(hConsole, 7);
		
					for(int i = 0; i < enemySent; i++){
						enemyArmy[i] = 'I';
					}
		
			        SetConsoleTextAttribute(hConsole, 3);
			        gotoxy(player.army.x, player.army.y);
			        printf("I");    
			        SetConsoleTextAttribute(hConsole, 7);
			        
			        
			        SetConsoleTextAttribute(hConsole, 4);
			        gotoxy(enemy.x, enemy.y);
			        printf("I");    
			        
	
			        for (int i = 0; i < enemySent; i++) {  
			            gotoxy(enemy.x, enemy.y + i);
			            printf(" %c", enemyArmy[i]);
			        }

			        SetConsoleTextAttribute(hConsole, 7);
			        
			        Sleep(50);
			        player.army.x++;  // Move right
	        		enemy.x--;  // Move left
				}
				
				int randNum = rand() % 3;
				if(enemySent > input){
					gotoxy(30, 4);
					print("Your troops were utterly crushed by the enemy forces!\n");
					if(randNum == 1){
						gotoxy(30, 5);
						print("The enemy took your soldiers into theirs, my lord!(33.33% chance)\n");
						enemy.soldiers += 1;
					} else if (randNum == 2){
						gotoxy(30, 5);
						print("No one died in today's battle, my lord!(33.33% chance)");
						player.army.soldiers += 1;
						enemy.soldiers += enemySent;
					} else {
						gotoxy(30, 5);
						print("Your soldier died on the battlefield, my lord!(33.33% chance)\n");
						enemy.soldiers += enemySent;
					}
				} else if(enemySent == input){
					gotoxy(30, 5);
					print("It's a tie");
				}
				Sleep(2000);
			}

			
			int index = 0;
			
			if(input >= 2){
				print("Arrange your soldiers my lord: ");
				scanf("%d %d", &player.army.row, &player.army.col);
				
				if(player.army.row < 0|| player.army.col < 0){
					print("Please input a correct row and col\n");
					continue;
				}
				
				
				for(int i = 0; i < player.army.row; i++){
					for(int j = 0; j < player.army.col; j++){
						arrangedArmy[i][j] = playerArmy[index++];
					}
				}
				
				SetConsoleTextAttribute(hConsole, 3);
				print("Your army now looks like this: \n");
				for(int i = 0; i < player.army.row; i++){
					for(int j = 0; j < player.army.col; j++){
						printf(" %c", arrangedArmy[i][j]);
					}
					printf("\n");
				}
				SetConsoleTextAttribute(hConsole, 7);
				printf("\n");
				printf("\n");
				
				
				SetConsoleTextAttribute(hConsole, 4);
				int minEnemy = input - 2;
				int maxEnemy = input + 2;
			    enemy.row = (rand() % player.army.soldiers) + 2;
				enemy.col = (rand() % player.army.soldiers) + 2;
				char enemyArrangedArmy[enemy.row][enemy.col];
				
				if (minEnemy < 1) minEnemy = 1;
				if (maxEnemy > enemy.soldiers) maxEnemy = enemy.soldiers;
				
				int enemySent = minEnemy + (rand() % (maxEnemy - minEnemy + 1));
				enemy.soldiers -= enemySent;
				char enemyArmy[enemySent];
				
				for(int i = 0; i < enemySent; i++){
					enemyArmy[i] = 'I';
				}
				
				int indexB = 0;
				for(int i = 0;i < enemy.row; i++){
					for(int j = 0; j < enemy.col; j++){
						enemyArrangedArmy[i][j] = (indexB < enemySent) ? enemyArmy[indexB++]: ' ';
					}
				}
				
				gotoxy(45, 15);
				printf("The enemy has sent %d Soldiers!\n", enemySent);
				
				Sleep(5000);
				
				
				player.army.x = 25;  
				player.army.y = 20;  
				enemy.x = 95;  
				enemy.y = 20; 
				
				for(int steps = 0; steps < 34; steps++){
					system("cls");  
					
					SetConsoleTextAttribute(hConsole, 3);
					printf("Soldiers left: %d\n", player.army.soldiers);
					gotoxy(0, 10);
					printPlayerCastle();
					SetConsoleTextAttribute(hConsole, 7);
					
					
					SetConsoleTextAttribute(hConsole, 4);
					gotoxy(100, 0);
					printf("Soldiers left: %d\n", enemy.soldiers);
					printEnemyCastle();
					SetConsoleTextAttribute(hConsole, 7);
					
					
					SetConsoleTextAttribute(hConsole, 3);
			        for (int i = 0; i < player.army.row; i++) {  
			            gotoxy(player.army.x, player.army.y + i);
			            for (int j = 0; j < player.army.col; j++) {
			                printf(" %c", arrangedArmy[i][j]);
			            }
			            printf("\n");
			        }
			        SetConsoleTextAttribute(hConsole, 7);
					
					SetConsoleTextAttribute(hConsole, 4);
			        for (int i = 0; i < enemy.row; i++) {  
			            gotoxy(enemy.x, enemy.y + i);
			            for (int j = 0; j < enemy.col; j++) {
			                printf(" %c", enemyArrangedArmy[i][j]);
			            }
			            printf("\n");  
			        }
			        SetConsoleTextAttribute(hConsole, 7);
			        
			        Sleep(20);
			        enemy.x--;
			        player.army.x++;
				}
				int randNum = rand() % 3;
				if(enemySent > input){
					gotoxy(30, 4);
					print("Your troops were utterly crushed by the enemy forces!\n");
					if(randNum == 1){
						gotoxy(30, 5);
						print("The enemy took your soldiers into theirs, my lord!(33.33% chance)\n");
						enemy.soldiers += enemySent;
						enemy.soldiers += player.army.soldiers;
					} else if (randNum == 2){
						gotoxy(24, 5);
						print("Everyone escaped and no one died in today's battle, my lord!(33.33% chance)");
						player.army.soldiers += input;
						enemy.soldiers += enemySent;
					} else {
						gotoxy(30, 5);
						print("Your soldier died on the battlefield, my lord!(33.33% chance)\n");
						enemy.soldiers += enemySent;
					} 
					Sleep(2000);
				} else if(input > enemySent){
					gotoxy(50, 4);
					print("You won the war!");
					if(randNum == 1){
						gotoxy(30, 5);
						print("You took the enemy soldiers into yours, my lord!(33.33% chance)\n");
						player.army.soldiers += input;
						player.army.soldiers += enemySent;
					} else if (randNum == 2){
						gotoxy(24, 5);
						print("Everyone escaped and no one died in today's battle, my lord!(33.33% chance)");
						player.army.soldiers += input;
						enemy.soldiers += enemySent;
					} else {
						gotoxy(30, 5);
						print("The enemy soldiers died on the battlefield, my lord!(33.33% chance)\n");
						player.army.soldiers += input;
					} 
					
				} else if(enemySent == input){
					gotoxy(50, 5);
					print("It's a tie");
				}
				Sleep(2000);
			}
		}
	}while(player.army.soldiers > 0 && enemy.soldiers > 0);

    if (enemy.soldiers <= 0) {
    	system("cls");
    	gotoxy(35, 15);
        print("Congratulations! You've defeated the enemy!\n");
        Sleep(2000);
        player.gold += 50; // Give gold reward
        printReturn();
        return player;
    }
}


void SoloGameplay(PLAYER player){
	int choice;
	int soldier;
	
	do{
		print("Welcome back to your kingdom!\n");
		print("Gold: ");
		printf("%dg\n", player.gold);
		print("Soldiers: ");
		printf("%d ", player.army.soldiers);
		print("soldiers\n");
		print("[1]Attack\n");
		print("[2]Buy Soldiers\n");
		print("[3]Farm for Gold\n");
		print("[4]Buy Farm(500g)\n");
		print("[0]Exit\n");
		print("CHOICE: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: 
			if(player.army.soldiers){
				player = attack(player);
			} else {
				print("Please buy soldiers to proceed!\n");
			}
		
			break;
			
			case 2: 
			if(player.gold > 5){
				print("How many soldiers do you wanna buy? (1 soldier = 5g)\n");
				print("Amount: ");
				scanf("%d", &soldier);
				
				if(player.gold >= soldier * 5){
					player.army.soldiers += soldier;
					print("You successfully bought ");
					printf("%d ", soldier);
					print("Soldiers!\n");
					
					player.gold -= soldier * 5;
					print("Gold left: ");
					printf("%dg\n", player.gold);
					printReturn();
					break;
				} else {
					print("You dont have enough gold!\n");
					printReturn();
					break;
				}
			} else {
				print("You dont have enough gold!\n");
				printReturn();
				break;
			}
			
			break;
			
			case 3: 
			if(player.farm == 1){
				player.gold += 20;
				print("You gained 20 gold from farming my lord!\n");
				print("Gold: ");
				printf("%dg\n", player.gold);
				printReturn();
			} else {
				print("You don't own a farm yet my lord!\n");
				printReturn();
			}
			break;
			
			case 4:
			if(player.gold >= 500 && player.farm != 1){
				player.farm = 1;
				player.gold -= 500;
				print("You successfully bought a farm my lord!\n");
				print("Gold: ");
				printf("%dg\n", player.gold);
				printReturn();
			} else if(player.farm == 1){
				print("You already own a farm!\n");
				printReturn();
				break;
			}else {
				print("You need more gold!\n");
				printReturn();
			}
		}
	}while(choice != 0);
}


void gotoxy(int column, int row) {
    COORD coord;
    coord.X = column;  // Horizontal position
    coord.Y = row;     // Vertical position
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

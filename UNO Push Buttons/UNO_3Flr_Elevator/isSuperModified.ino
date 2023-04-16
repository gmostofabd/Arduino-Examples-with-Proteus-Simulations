/*made by me: I Earl John B. Masaga BSECE student
~Elevator arduino~
LAST MODIFIED: APRIL 5, 2021*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

/*setting of buttons*/
const int isGround = 8;
const int is2Floor = 9;
const int is3Floor = 10;
const int is4Floor = 11;
const int isUP = 12;
const int isDOWN = 13;

/*main steup*/
void setup() {
  lcd.begin(16,2);
  lcd.clear();

  /*set all buttons to low input*/
  pinMode(isGround, INPUT);
  digitalWrite(isGround, LOW);
  pinMode(is2Floor, INPUT);
  digitalWrite(is2Floor, LOW);
  pinMode(is3Floor, INPUT);
  digitalWrite(is3Floor, LOW);
  pinMode(is4Floor, INPUT);
  digitalWrite(is4Floor, LOW);
  pinMode(isUP, INPUT);
  digitalWrite(isUP, LOW);
  pinMode(isDOWN, INPUT);
  digitalWrite(isDOWN, LOW);
}
/*variables section or the parameters for our loops*/

/*display of current floor*/
String isCurrent = "Ground";
/*current floor*/
int isOption = 1; /* number 1 is ground */

/*case switch*/
int isSwitch = 0;
/*variable that will break the while loop*/
int isPasser = 0;
/*the one that can disable the buttons*/
int isGood = 0;

/*important variables for stacking of button press*/
int isInline1 = 0;
int isInline2 = 0;
int isInline3 = 0;
int isInline4 = 0;

/*beginning of the process*/
void loop() {
  /*default display*/
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Current Floor");
  lcd.setCursor(4,1);
  lcd.print(isCurrent);
  delay(2000);

  /*this loop will give the user limited time of selection of up and down*/
  for(int i = 0; i<=30; i++){
    /*condition for every floor*/
    if(isOption==1){
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("Select");
      lcd.setCursor(7,1);
      lcd.print("UP");
      delay(100);
      /*condition for disabling buttons*/
      if(digitalRead(isDOWN)==HIGH){
        isGood = 0;
      }else if(digitalRead(isUP)==HIGH){
         isGood = 1;
       }
    }else if(isOption==4){
       lcd.clear();
       lcd.setCursor(5,0);
       lcd.print("Select");
       lcd.setCursor(6,1);
       lcd.print("DOWN");
       delay(100);
       if(digitalRead(isUP)==HIGH){
         isGood = 0;
       }else if(digitalRead(isDOWN)==HIGH){
          isGood = 1;
        }
     }else if(isOption==2){
        lcd.clear();
        lcd.setCursor(5,0);
        lcd.print("Select");
        lcd.setCursor(1,1);
        lcd.print("  UP    DOWN");
        delay(100);
        if(digitalRead(isUP)==HIGH || digitalRead(isDOWN)==HIGH){
          isGood = 1;
        }
      }else if(isOption==3){
         lcd.clear();
         lcd.setCursor(5,0);
         lcd.print("Select");
         lcd.setCursor(1,1);
         lcd.print("  UP    DOWN");
         delay(100);
         if(digitalRead(isUP)==HIGH || digitalRead(isDOWN)==HIGH){
           isGood = 1;
         }
       }

    /*if is "isGood" true, it will proceed to this part*/   
    if(isGood==1){
      /*display of the elevator door*/
      lcd.clear();
      delay(500);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1500);
      /*setting the default parameter for our while loop*/
      isPasser = 1;
      isGood = 0;
      /*again isPasser is their to prevent the while loop to function*/
      while(digitalRead(isGround)==LOW && digitalRead(is2Floor)==LOW && digitalRead(is3Floor)==LOW  && digitalRead(is4Floor)==LOW && isPasser == 1){
        /*display the selection floors*/
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("Select Floor");
        lcd.setCursor(1,1);
        lcd.print("G   2   3   4");
        delay(100);

  /*conditions to capture the g, 2, 3, 4, button press*/ 
  if(digitalRead(isGround)==HIGH && isOption == 1){
    /*Ground*/
    isSwitch = 1;
    /*for loop to give limited time to the user if ever daghan tao musulod sa elevator*/
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      /*if statements for capturing button press in the given limited time*/
      if(digitalRead(is2Floor)==HIGH){
        isInline2 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is2Floor)==HIGH && isOption == 1){
    /*2nd Floor*/
    isSwitch = 2;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is3Floor)==HIGH && isOption == 1){
    /*3rd Floor*/
    isSwitch = 3;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is2Floor)==HIGH){
         isInline2 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is4Floor)==HIGH && isOption == 1){
    /*4th Floor*/
    isSwitch = 4;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is2Floor)==HIGH){
          isInline2 = 1;
        }
    }
  }
  else if(digitalRead(isGround)==HIGH && isOption == 2){
    /*Ground*/
    isSwitch = 5;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(is2Floor)==HIGH){
        isInline2 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is2Floor)==HIGH && isOption == 2){
    /*2nd Floor*/
    isSwitch = 14;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is3Floor)==HIGH && isOption == 2){
    /*3rd Floor*/
    isSwitch = 6;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is2Floor)==HIGH){
         isInline2 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is4Floor)==HIGH && isOption == 2){
    /*4th Floor*/
    isSwitch = 7;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is2Floor)==HIGH){
          isInline2 = 1;
        }
    }
  }
  else if(digitalRead(isGround)==HIGH && isOption == 3){
    /*Ground*/
    isSwitch = 8;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(is2Floor)==HIGH){
        isInline2 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is2Floor)==HIGH && isOption == 3){
    /*2nd Floor*/
    isSwitch = 9;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is3Floor)==HIGH && isOption == 3){
    /*3rd Floor*/
    isSwitch = 15;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is2Floor)==HIGH){
         isInline2 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is4Floor)==HIGH && isOption == 3){
    /*4th Floor*/
    isSwitch = 10;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is2Floor)==HIGH){
          isInline2 = 1;
        }
    }
  }
  else if(digitalRead(isGround)==HIGH && isOption == 4){
    /*Ground*/
    isSwitch = 11;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(is2Floor)==HIGH){
        isInline2 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is2Floor)==HIGH && isOption == 4){
    /*2nd Floor*/
    isSwitch = 12;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is4Floor)==HIGH){
          isInline4 = 1;
        }
    }
  }
  else if(digitalRead(is3Floor)==HIGH && isOption == 4){
    /*3rd Floor*/
    isSwitch = 13;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is4Floor)==HIGH){
         isInline4 = 1;
       }else if(digitalRead(is2Floor)==HIGH){
          isInline2 = 1;
        }
    }
  }
  else if(digitalRead(is4Floor)==HIGH && isOption == 4){
    /*4th Floor*/
    isSwitch = 16;
    for(int i = 0; i<=40; i++){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Select Floor");
      lcd.setCursor(1,1);
      lcd.print("G   2   3   4");
      delay(100);
      if(digitalRead(isGround)==HIGH){
        isInline1 = 1;
      }else if(digitalRead(is3Floor)==HIGH){
         isInline3 = 1;
       }else if(digitalRead(is2Floor)==HIGH){
          isInline2 = 1;
        }
    }
  }

  /*main process*/  
  switch(isSwitch){
    case 1:
      /*isSwitch is set to zero for preventing the program to jump to this switch statement*/
      isSwitch = 0;
      /*as you can see isPasser is set to zero for it to break the while loop kanina*/
      isPasser = 0;
      /*condition that will capture the bonus presses or you can say presses of the other users*/
      if(isInline2 == 1){
        /*this is the fun part that i used, manipulation of variables in every loop using the isInline variable*/
        isInline2 = 0;
        /*this go to satement will loop to the next floor*/
        goto is2Tile;
      }else if(isInline3 == 1){
         isInline3 = 0;
         goto is3Tile;
       }else if(isInline4 == 1){
          isInline4 = 0;
          goto is4Tile;
        }
      /*if no presses in the given limited time, it ends here, changing the variable of the isCurrent*/  
      isCurrent = "Ground";
      /*going back to the defalut display*/
      loop();
      /*this break statement is optionla but it is a good practice for programmers to set break points*/
      break;
    case 2:
      is2Tile:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("UP [G]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("UP [2]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 2;
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_2;
      }else if(isInline4 == 1){
         isInline4 = 0;
         goto is4Tile_2;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_2;
        }
      isCurrent = "2nd Floor";
      loop();
      break;
    case 3:
      is3Tile:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("UP [G]");
      for(int i = 2; i<=3; i++){
        delay(2000);
        lcd.setCursor(4,1);
        lcd.print("UP [");
        lcd.setCursor(8,1);
        lcd.print(i);
        lcd.setCursor(9,1);
        lcd.print("]");
      }
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 3;
      isSwitch = 0;
      isPasser = 0;
      if(isInline4 == 1){
        isInline4 = 0;
        goto is4Tile_3;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_3;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_3;
        }
      isCurrent = "3rd Floor";
      loop();
      break;
    case 4:
      is4Tile:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("UP [G]");
      for(int i = 2; i<=4; i++){
        delay(2000);
        lcd.setCursor(4,1);
        lcd.print("UP [");
        lcd.setCursor(8,1);
        lcd.print(i);
        lcd.setCursor(9,1);
        lcd.print("]");
      }
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 4;
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_4;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_4;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_4;
        }
      isCurrent = "4th Floor";
      loop();
      break;
    case 5:
      is1Tile_2:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("DOWN [2]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("DOWN [G]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 1;
      isSwitch = 0;
      isPasser = 0;
      if(isInline2 == 1){
        isInline2 = 0;
        goto is2Tile;
      }else if(isInline3 == 1){
         isInline3 = 0;
         goto is3Tile;
       }else if(isInline4 == 1){
          isInline4 = 0;
          goto is4Tile;
        }
      isCurrent = "Ground";
      loop();
      break;
    case 6:
      is3Tile_2:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("UP [2]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("UP [3]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 3;
      isSwitch = 0;
      isPasser = 0;
      if(isInline4 == 1){
        isInline4 = 0;
        goto is4Tile_3;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_3;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_3;
        }
      isCurrent = "3rd Floor";
      loop();
      break;
    case 7:
      is4Tile_2:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("UP [2]");
      for(int i = 3; i<=4; i++){
        delay(2000);
        lcd.setCursor(4,1);
        lcd.print("UP [");
        lcd.setCursor(8,1);
        lcd.print(i);
        lcd.setCursor(9,1);
        lcd.print("]");
      }
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 4;
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_4;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_4;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_4;
        }
      isCurrent = "4th Floor";
      loop();
      break;
    case 8:
      is1Tile_3:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("DOWN [3]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("DOWN [2]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("DOWN [G]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 1;
      isSwitch = 0;
      isPasser = 0;
      if(isInline2 == 1){
        isInline2 = 0;
        goto is2Tile;
      }else if(isInline3 == 1){
         isInline3 = 0;
         goto is3Tile;
       }else if(isInline4 == 1){
          isInline4 = 0;
          goto is4Tile;
        }
      isCurrent = "Ground";
      loop();
      break;
    case 9:
      is2Tile_3:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("DOWN [3]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("DOWN [2]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 2;
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_2;
      }else if(isInline4 == 1){
         isInline4 = 0;
         goto is4Tile_2;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_2;
        }
      isCurrent = "2nd Floor";
      loop();
      break;
    case 10:
      is4Tile_3:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("UP [3]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("UP [4]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 4;
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_4;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_4;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_4;
        }
      isCurrent = "4th Floor";
      loop();
      break;
    case 11:
      is1Tile_4:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("DOWN [4]");
      for(int i = 3; i>=2; i--){
        delay(2000);
        lcd.setCursor(4,1);
        lcd.print("DOWN [");
        lcd.setCursor(10,1);
        lcd.print(i);
        lcd.setCursor(11,1);
        lcd.print("]");
      }
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("DOWN [G]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 1;
      isSwitch = 0;
      isPasser = 0;
      if(isInline2 == 1){
        isInline2 = 0;
        goto is2Tile;
      }else if(isInline3 == 1){
         isInline3 = 0;
         goto is3Tile;
       }else if(isInline4 == 1){
          isInline4 = 0;
          goto is4Tile;
        }
      isCurrent = "Ground";
      loop();
      break;
    case 12:
      is2Tile_4:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("DOWN [4]");
      for(int i = 3; i>=2; i--){
        delay(2000);
        lcd.setCursor(4,1);
        lcd.print("DOWN [");
        lcd.setCursor(10,1);
        lcd.print(i);
        lcd.setCursor(11,1);
        lcd.print("]");
      }
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 2;
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_2;
      }else if(isInline4 == 1){
         isInline4 = 0;
         goto is4Tile_2;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_2;
        }
      isCurrent = "2nd Floor";
      loop();
      break;
    case 13:
      is3Tile_4:
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("DOWN [4]");
      delay(2000);
      lcd.setCursor(4,1);
      lcd.print("DOWN [3]");
      delay(1000);
      lcd.setCursor(4,1);
      lcd.print("Door Opened");
      delay(3000);
      lcd.setCursor(4,1);
      lcd.print("Door Closed");
      delay(1000);
      isOption = 3;
      isSwitch = 0;
      isPasser = 0;
      if(isInline4 == 1){
        isInline4 = 0;
        goto is4Tile_3;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_3;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_3;
        }
      isCurrent = "3rd Floor";
      loop();
      break;
    case 14:
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_2;
      }else if(isInline4 == 1){
         isInline4 = 0;
         goto is4Tile_2;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_2;
        }
      isCurrent = "2nd Floor";
      loop();
      break;
    case 15:
      isSwitch = 0;
      isPasser = 0;
      if(isInline4 == 1){
        isInline4 = 0;
        goto is4Tile_3;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_3;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_3;
        }
      isCurrent = "3rd Floor";
      loop();
      break;
    case 16:
      isSwitch = 0;
      isPasser = 0;
      if(isInline3 == 1){
        isInline3 = 0;
        goto is3Tile_4;
      }else if(isInline2 == 1){
         isInline2 = 0;
         goto is2Tile_4;
       }else if(isInline1 == 1){
          isInline1 = 0;
          goto is1Tile_4;
        }
      isCurrent = "4th Floor";
      loop();
      break;
      }
     }
    }
  }
}

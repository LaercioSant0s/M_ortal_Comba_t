#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {

  char value;
  struct Node *next;

} Node;

typedef struct Queue {

  Node *head;
  Node *tail;
  int size;

} Queue;

void initQueue(Queue *queue) {

  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;

}

void enqueue(Queue *queue, char value) {

  Node *node = malloc(sizeof(Node));

  if (node == NULL) {
    perror("Fail to allocate memory");
    exit(1);
  }

  node->value = value;
  node->next = NULL;
  
  if (queue->head == NULL)
  {

    queue->head = node;
    queue->tail = node;
    queue->size += 1;
    return;
    
  }

  Node *actual = queue->head;
  Node *previous = actual;

  while (actual != NULL) {

    previous = actual;
    actual = actual->next;

  }

  previous->next = node;
  queue->tail = node;
  queue->size += 1;
  
}

void dequeue(Queue *queue) {

  if (queue->head == NULL)
  {
    printf("Queue already empty");
    return;
  }

  if (queue->head->next == NULL)
  {
    free(queue->head);
    queue->head = NULL;
    queue->tail = NULL;
    queue->size -= 1;
    return;
  }

  Node *aux = queue->head;
  queue->head = queue->head->next;
  
  aux->next = NULL;
  free(aux);

  queue->size -= 1;
  
}

void enqueueSequence(Queue *queue, char *attacks) {

  int attacksLen = strlen(attacks);

  if (attacks[0] == '0') {
    return;
  }

  for (int i = 0; i < attacksLen ; i++) {

    if (queue->size == 20) {
      dequeue(queue);
    }

    enqueue(queue, attacks[i]);

  }
  
}

void printQueue(Queue *queue) {

  if (queue->size == 0) {
    return;
  }

  Node *actual = queue->head;

  while (actual != NULL) {

    printf("%c", actual->value);
    actual = actual->next;
    
  }
  
}

struct jogador {

  int vidaJogador;
  int estaminaJogador;
  int multiplicadorJogador;
  Queue historico;

};

int validWords(char *palavra) {

  if (strncmp(palavra, "ARROZAO", 7) == 0) {

    strcpy(palavra, "ARROZAO");

  } else if (strncmp(palavra, "DADBAD", 6) == 0) {

    strcpy(palavra, "DADBAD");

  } else if (strncmp(palavra, "STTEACC", 7) == 0) {

    strcpy(palavra, "STTEACC");

  } else if (strncmp(palavra, "TATAPAAA", 8) == 0) {

    strcpy(palavra, "TATAPAAA");

  } else {

    // Apenas 4 ataques no máx, ZZZZ OU AZAZ

    int inputLength = strlen(palavra); // \n

    if (inputLength > 4 + 1) { // \n included 

      return -1;

    }

    for (int i = 0; i < inputLength; i++) {

      switch (palavra[i]) {

        case 'Z': palavra[i] = 'Z'; break;
        case 'P': palavra[i] = 'P'; break;
        case 'A': palavra[i] = 'A'; break;
        case 'E': palavra[i] = 'E'; break;
        case 'T': palavra[i] = 'T'; break;
        case 'R': palavra[i] = 'R'; break;
        case 'C': palavra[i] = 'C'; break;
        case 'B': palavra[i] = 'B'; break;
        case 'O': palavra[i] = 'O'; break;
        case 'M': palavra[i] = 'M'; break;
        case 'D': palavra[i] = 'D'; break;
        case ' ': palavra[i] = ' '; break;
        case '\n': palavra[i] = '\0'; break;


        default: return -1;

      }

    }

  }

  return 0;

}

int validarInput(char *input) {

  fgets(input, 10, stdin); //stdin(Máx word 8 letters + \n) + \0 (fgets) (array 10 char)
                          // to include invalid words i will add one more space in the array

  int validInput = validWords(&input[0]); //-1 if invalid word, 0 if valid word


  return validInput;

}

int mapeamentoEfeitos(char ataqueJogador1, char ataqueJogador2) {

  int efeitos[12][12] = {
  
    {  0  ,  4  ,  8  ,  12 ,  16 , -20 , -16 ,  12 , -8  , -4  ,  0  ,  20 },
    { -4  ,  0  ,  4  ,  8  ,  12 ,  16 , -20 , -16 , -12 ,  16 ,  0  ,  20 },
    { -8  , -4  ,  0  ,  4  ,  8  ,  12 ,  16 , -20 , -16 ,  12 ,  0  ,  20 },
    { -12 , -8  , -4  ,  0  ,  4  , -8  ,  12 ,  16 ,  20 , -16 ,  0  ,  20 },
    { -16 , -12 , -8  , -4  ,  0  ,  4  , -8  ,  12 ,  16 ,  20 ,  0  ,  20 },
    {  20 , -16 , -12 ,  8  , -4  ,  0  ,  4  ,  8  ,  12 , -16 ,  0  ,  20 },
    {  16 ,  20 , -16 , -12 ,  8  , -4  ,  0  , -8  , -4  , -8  ,  0  ,  20 },
    { -12 ,  16 ,  20 , -16 , -12 , -8  ,  8  ,  0  ,  16 , -20 ,  0  ,  20 },
    {  8  ,  12 ,  16 ,  20 , -16 , -12 ,  4  , -16 ,  0  ,  20 ,  0  ,  20 },
    {  4  , -16 , -12 ,  16 , -20 ,  16 ,  8  ,  20 , -20 ,  0  ,  0  ,  20 },
    { -20 , -20 , -20 , -20 , -20 , -20 , -20 , -20 , -20 , -20 ,  0  ,  0  }
   
  };  

  int i;
  int j;

  switch (ataqueJogador1) {

    case 'Z': i = 0; break;
    case 'P': i = 1; break;
    case 'A': i = 2; break;
    case 'E': i = 3; break;
    case 'T': i = 4; break;
    case 'R': i = 5; break;
    case 'C': i = 6; break;
    case 'B': i = 7; break;
    case 'O': i = 8; break;
    case 'M': i = 9; break;
    case 'D': i = 10; break;
    case ' ': i = 11; break;

    default: return -1;

  }

  switch (ataqueJogador2) {

    case 'Z': j = 0; break;
    case 'P': j = 1; break;
    case 'A': j = 2; break;
    case 'E': j = 3; break;
    case 'T': j = 4; break;
    case 'R': j = 5; break;
    case 'C': j = 6; break;
    case 'B': j = 7; break;
    case 'O': j = 8; break;
    case 'M': j = 9; break;
    case 'D': j = 10; break;
    case ' ': j = 11; break;

    default: return -1;

  }
  
  return efeitos[i][j];
    
}

void multiplier(struct jogador *player) {

  if (player->estaminaJogador > 750) {

    player->multiplicadorJogador = 1;

  } else if (player->estaminaJogador > 500) {

    player->multiplicadorJogador = 2;

  } else if (player->estaminaJogador > 250) {

    player->multiplicadorJogador = 3;

  } else if (player->estaminaJogador < 250) {

    player->multiplicadorJogador = 4;

  }
  
}

void applyLiveAndStamina(struct jogador *player, int life, int estamina) {

  if (player->vidaJogador + life > 1000) {
    player->vidaJogador = 1000;
  } else {
    player->vidaJogador += life;
  }

  if (estamina > 0) {

    if (player->estaminaJogador + estamina > 1000) {
      player->estaminaJogador = 1000;
    } else {
      player->estaminaJogador += estamina;
    }
    
  } else {

    if (player->estaminaJogador + estamina < 0) {
      player->estaminaJogador = 0;
    } else {
      player->estaminaJogador += estamina;
    }

  }
  
}

void processadorEfeitos(struct jogador *playersTurn, char *playerAttack, struct jogador *playerAffected, char *playerAffectedAttack) {

  int wordP1Length = strlen(playerAttack);
  int wordPALength = strlen(playerAffectedAttack);
  
  
  if (wordP1Length > 4) // combo P1
  { 

    if (strncmp(playerAttack, "ARROZAO", 7) == 0) {

      if (playersTurn->estaminaJogador > 750) {
        
        playerAffected->vidaJogador -= 500;
        playersTurn->estaminaJogador -= 500;
        
      } else {

        printf("Estamina insuficiente");
        
      }
      
    } else if (strncmp(playerAttack, "DADBAD", 6) == 0) {

      if (playersTurn->estaminaJogador > 750) {

        playerAffected->vidaJogador -= 400;
        playersTurn->estaminaJogador -= 400;

      } else {

        printf("Estamina insuficiente");

      }
      
    } else if (strncmp(playerAttack, "STTEACC", 7) == 0) {

      if (playersTurn->estaminaJogador > 750) {

        playerAffected->vidaJogador -= 300;
        playersTurn->estaminaJogador -= 300;

      } else {

        printf("Estamina insuficiente");

      }
      
    } else if (strncmp(playerAttack, "TATAPAAA", 8) == 0) {

      if (playersTurn->estaminaJogador > 750) {

        playerAffected->vidaJogador -= 200;
        playersTurn->estaminaJogador -= 200;

      } else {

        printf("Estamina insuficiente");

      }

    }
    
  }
  
  if (wordPALength > 4) // combo P2
  { 

    if (strncmp(playerAffectedAttack, "ARROZAO", 7) == 0) {

        if (playerAffected->estaminaJogador > 750) {

          playersTurn->vidaJogador -= 500;
          playerAffected->estaminaJogador -= 500;

        } else {

          printf("Estamina insuficiente");

        }

      } else if (strncmp(playerAffectedAttack, "DADBAD", 6) == 0) {

        if (playerAffected->estaminaJogador > 750) {

          playersTurn->vidaJogador -= 400;
          playerAffected->estaminaJogador -= 400;

        } else {

          printf("Estamina insuficiente");

        }

      } else if (strncmp(playerAffectedAttack, "STTEACC", 7) == 0) {

        if (playerAffected->estaminaJogador > 750) {

          playersTurn->vidaJogador -= 300;
          playerAffected->estaminaJogador -= 300;

        } else {

          printf("Estamina insuficiente");

        }

      } else if (strncmp(playerAffectedAttack, "TATAPAAA", 8) == 0) {

        if (playerAffected->estaminaJogador > 750) {

          playersTurn->vidaJogador -= 200;
          playerAffected->estaminaJogador -= 200;

        } else {

          printf("Estamina insuficiente");

        }

      }

    }

  if (wordP1Length <= 4 && wordPALength <= 4) //normal a P1 and P2 attack 
  {

    for (int i = 0, j = 0; i < wordP1Length || j < wordPALength; ) {

      char effectI = ' ';
      char effectJ = ' ';

      int effect;
      
      if (i < wordP1Length && j < wordPALength) {

        effectI = playerAttack[i], effectJ = playerAffectedAttack[j];
        
        effect = mapeamentoEfeitos(effectI, effectJ);
        i++, j++;
        
      } else if (i == wordP1Length) {

        effectJ = playerAffectedAttack[j];
        
        effect = mapeamentoEfeitos(effectI,effectJ);
        j++;

      } else if (j == wordPALength) {

        effectI = playerAttack[i];

        effect = mapeamentoEfeitos(effectI,effectJ);
        i++;

      }

      multiplier(playersTurn);
      multiplier(playerAffected);

      if (effectI == ' ') {

        applyLiveAndStamina(playersTurn, 0, 25);
        
      } else if (effectI == 'D') {

        applyLiveAndStamina(playersTurn, 10 * playersTurn->multiplicadorJogador, -10);
        
      } else {

        applyLiveAndStamina(playersTurn, 0, -25);

      }

      if (effectJ == ' ') {

        applyLiveAndStamina(playerAffected, 0, 25);

      } else if (effectJ == 'D') {

        applyLiveAndStamina(playerAffected, 10 * playerAffected->multiplicadorJogador, -10);

      } else {

        applyLiveAndStamina(playerAffected, 0, -25);

      }

      if (effect >= 0) {

        playerAffected->vidaJogador -= effect;
        
      }

      //******Second player*******

      if (effect <= 0) { 

        playersTurn->vidaJogador += effect;
        
      }
      
    }

  }
  
}


void estruturaAtaques(char *ataquesJogador1, char *ataquesJogador2) {

  int lenWordPlayer1 = strlen(ataquesJogador1);
  int lenWordPlayer2 = strlen(ataquesJogador2);
  
  if (lenWordPlayer1 > 4 && lenWordPlayer2 > 4) {

    printf("[%s|%s]\n", ataquesJogador1, ataquesJogador2);
    
  } else if (lenWordPlayer1 > 4) {

    printf("[%s| ]\n", ataquesJogador1);

  } else if (lenWordPlayer2 > 4) {

    printf("[ |%s]\n", ataquesJogador2);
    
  } else {
    
    for (int i = 0, j = 0; i < lenWordPlayer1 || j < lenWordPlayer2 ; ) {

      if (i < lenWordPlayer1 && j < lenWordPlayer2) {

        printf("[%c|%c]", ataquesJogador1[i], ataquesJogador2[j]);
        i++, j++;

      } else if (i == lenWordPlayer1) {

        printf("[ |%c]", ataquesJogador2[j]);
        j++;
        
      } else if (j == lenWordPlayer2) {
        
        printf("[%c| ]", ataquesJogador1[i]);
        i++;
 
      }
      
    }

    printf("\n");

  }

}


int cicloJogo(struct jogador *jogador1, char *ataqueJogador1, struct jogador *jogador2, char *ataqueJogador2) {

  printf("P#1[%d|%d] (x%d)\n", jogador1->vidaJogador, jogador1->estaminaJogador, jogador1->multiplicadorJogador);
  printf("H: "); printQueue(&jogador1->historico); //todo: histórico de ataques
  printf("\nI: ");

  int inputValue = validarInput(&ataqueJogador1[0]);
  
  if (inputValue == -1) {
    return -1;
  }

  enqueueSequence(&jogador1->historico, &ataqueJogador1[0]);
  

  //--------------------------------------------------------------------

  printf("P#2[%d|%d] (x%d)\n", jogador2->vidaJogador, jogador2->estaminaJogador, jogador2->multiplicadorJogador);
  printf("H: "); printQueue(&jogador2->historico); //todo: histórico de ataques
  printf("\nI: ");

  inputValue = validarInput(&ataqueJogador2[0]);

  if (inputValue == -1) {
    return -1;
  }

  enqueueSequence(&jogador2->historico, &ataqueJogador2[0]);

  //--------------------------------------------------------------------

  estruturaAtaques(&ataqueJogador1[0], &ataqueJogador2[0]);

  processadorEfeitos(&jogador1[0], &ataqueJogador1[0], &jogador2[0], &ataqueJogador2[0]);

  return 0;
  
}


int main(void) {

  struct jogador jogador1 = {1000, 1000, 1};
  struct jogador jogador2 = {1000, 1000, 1};

  char ataqueJogador1[11];
  ataqueJogador1[0] = '0';
  
  char ataqueJogador2[11];
  ataqueJogador2[0] = '0';

  initQueue(&jogador1.historico);
  initQueue(&jogador2.historico);

  while (jogador1.vidaJogador > 0 && jogador2.vidaJogador > 0) {
  
    int game = cicloJogo(&jogador1, &ataqueJogador1[0], &jogador2, &ataqueJogador2[0]);
  
    if (game == -1) {
  
      printf("Entrada invalida\n");
      
      return -1;
      
    }
    
  }

  if (jogador1.vidaJogador < 0) {

    printf("jogador 2 venceu o jogo!");
    
  } else {

    printf("jogador 1 venceu o jogo!");
    
  }

  return 0;
  
}
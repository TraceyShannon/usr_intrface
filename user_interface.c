#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct players {
  char user_name[30];
  int age;
  int score;
  int high_score;
};

struct players player_one;

int check_input();

void print_space();

int get_numbers(int);

void print_instructions();

void init(int, struct players *);

struct players game(struct players *);

void check_profile(struct players *);

void print_profile(struct players *);

void create_profile(struct players *);

void update_profile(struct players *);

// ==== User Commands ==== //
int quit = 01;
int profile = 02;
int start_game = 03;
int create_space = 04;
int print_instruct = 05;

// ==== Begin Main Function ==== //
int main(int argc, char const *argv[]) {

  int user_input;

  // ==== Game Loop ==== //
  while (user_input != quit) {

    print_instructions();
    printf("\nEnter Code: ");

    scanf("%d", &user_input);

    init(user_input, &player_one);

  }

  return 0;
}
// ==== End Main Function ==== //

void check_profile(struct players *user) {

  // ==== Profile Commands ==== //
  int create = 00;
  int update = 11;
  int exit = 99;

  int user_input = 0;
  printf("\n** Please Type 00 To Create Profile **\n");
  printf("** Please Type 11 To Update Profile **\n");
  printf("** Please Type 99 To Exit **\n\n");

  while (user_input != exit) {

    print_profile(user);

    if (user->age == 0) {
      printf("There's No Username Here! Type 00 To Fix That!\n\n");
    } else {
      printf("\nWelcome Back, %s!\n\n", user->user_name);
    }

    printf("Enter Profile Command: ");

    scanf("%d", &user_input);

    if (user_input == create && user->age == 0) {
      printf("Cool, Let's Get Started!\n");
      create_profile(user);
    } else if (user_input == update && user->age != 0) {
      printf("Cool, Let's Get Started!\n");
      update_profile(user);
    }

  }

}

int get_numbers(int count) {

  int random_number = 0;
  int res = 1;

  srand(time(0));

  printf("\n");
  for (int i = 0; i < count; i++) {
    random_number = rand() % 10 + 1;
    res *= random_number;
    if (i >= count - 1) {
      printf("%d", random_number);
    } else {
      printf("%d x ", random_number);
    }
  }
  printf("\n");

  return res;
}

int check_input(int user_input, int res) {

  int final_res = 0;

  if (user_input == res) {
    printf("\nThat's Correct! Good Job!\n");
    final_res = 100;
  } else if (user_input != res && user_input != quit && user_input != profile && user_input != start_game && user_input != print_instruct) {
    printf("\nSorry That's Incorrect...\n");
  }

  return final_res;
}

void print_instructions() {

  printf("\n** Please Type 01 To Quit! **\n");
  printf("** Please Type 02 To Check Your Profile! **\n");
  printf("** Please Type 03 To Sart The Game! **\n");
  printf("** Please Type 04 To Make Some Space! **\n");
  printf("** Please Type 05 To Print The Instructions! **\n\n");

}

struct players game(struct players *user) {

  // ==== Game Commands ==== //
  int end_early = 001;

  int rounds;
  int res;
  int score = 0;
  int i = 0;
  int numbers = 0;
  int user_input = 0;

  printf("\nHow Many Rounds Would You Like To Play?: ");
  scanf("%d", &rounds);

  while (rounds > 100 || rounds < 1) {
    printf("\nThat's Not A Number I Can Deal With Friend, Sorry...Try Again.\n");
    printf("\nHow Many Rounds Would You Like To Play?: ");
    scanf("%d", &rounds);
  }

  printf("\nHow Many Numbers Would You Like To Multiply?: ");
  scanf("%d", &numbers);

  while (numbers > 10 || numbers < 1) {
    printf("\nThat's Not A Number I Can Deal With Friend, Sorry...Try Again.\n");
    printf("\nHow Many Numbers Would You Like To Multiply?: ");
    scanf("%d", &numbers);
  }

  printf("** Please Type 001 To End The Game Early **\n");

  while (i < rounds) {
    printf("\nCurrent Score: { %d }\n\n", score);
    res = get_numbers(numbers);
    scanf("%d", &user_input);
    if (user_input == end_early) {
      break;
    }
    score += check_input(user_input, res);
    i++;
  }
  printf("\nFinal Score: { %d }\n\n", score);
  user->score = score;
  if (user->score > user->high_score) {
    user->high_score = user->score;
  }
  printf("Great Job!\n\n");
  printf("GAME OVER!\n\n");

  return *user;
}

void init(int user_input, struct players *user) {

  if (user_input == quit) {
    printf("Bye!\n");
  } else if (user_input == profile) {
    check_profile(user);
  } else if (user_input == start_game) {
    game(user);
  } else if (user_input == create_space) {
    print_space();
  } else if (user_input == print_instruct) {
    print_instructions();
  }

}

 void create_profile(struct players *user) {

  printf("\nPlease Enter Your Username: ");
  scanf("%s", user->user_name);

  printf("\nPlease Enter Your Age: ");
  scanf("%d", &user->age);

  printf("\nBeautiful We Are All Done Here! Welcome %s\n\n", user->user_name);

}

void update_profile(struct players *user) {

  // ==== Update Commands ==== //
  int exit = 10;
  int update_age = 12;
  int update_user_name = 13;

  int user_input = 0;

  while (user_input != exit) {

    printf("\nWhat Would You Like To Update: \n\n");

    printf("** To Exit Type 10 **\n");
    printf("** To Update Age Type 12 **\n");
    printf("** To Update Username Type 13 **\n\n");

    printf("Enter Update Command: ");
    scanf("%d", &user_input);

    if (user_input == update_user_name) {
      printf("What Would You Like To Change Your Username To: ");
      scanf("%s", user->user_name);

      for (int i = 0; i < 80; i++) {
        printf("=");
      }

      printf("\n** Your Username Has Been Successfully Updated **\n");

      for (int i = 0; i < 80; i++) {
        printf("=");
      }
      printf("\n");

    } else if (user_input == update_age) {
      printf("What Would You Like To Change Your Age To: ");
      scanf("%d", &user->age);

      for (int i = 0; i < 80; i++) {
        printf("=");
      }

      printf("\n** Your Age Has Been Successfully Updated **\n");

      for (int i = 0; i < 80; i++) {
        printf("=");
      }
      printf("\n");

    }

  }



}

void print_profile(struct players *user) {

  for (int i = 0; i <= 140; i++) {
    printf("=");
  }
  printf("\n");

  for (int i = 0; i < 1; i++) {
    printf("|\t|Username: { %s }|\t|", user->user_name);
    printf("|\t|Age: { %d }|\t|", user->age);
    printf("|\t|Last Score: { %d }|\t|", user->score);
    printf("|\t|High Score: { %d }|\t|", user->high_score);
  }
  printf("\n");

  for (int i = 0; i <= 140; i++) {
    printf("=");
  }
  printf("\n");

}

void print_space() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

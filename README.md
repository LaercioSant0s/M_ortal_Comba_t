> Status: Developing, final testing phase⚠️

# M_ortal Comba_t (C)

Basic and fuctional fight game that allow two players do choose a set of attacks and combos
that do more damage and consume a significative ammount of stamina.


## Functional

- Each player starts with 1000 life and 1000 stamina and a multiplier.
- One player wins if the others life reach 0 life points or under.
- An attack is a single letter "C" or "A" (not more than 4 letters).
- One player can make up to 4 attacks per round "CCAA" or "AZ".
- Each attack consume 25 stamina points, except "D" and " ".
- A combo is special sequence of expected letter (pos-explanation).
- Per round a player can´t mix attacks with combos.

## Layout

![image](https://github.com/LaercioSant0s/M_ortal_Comba_t/assets/127317610/b703c0d9-3239-4337-b0b7-c91b4fd6898e)

## Attacks

The following attacks included in the game are:

![image](https://github.com/LaercioSant0s/M_ortal_Comba_t/assets/127317610/1734db4b-ea8c-469c-9737-25cc27017cd3)

"D" consume -10 stamina points and restore +10 life points <br>
" " restore +25 stamina points <br>

For the effects i compare the first attack of player one with the first attack of player two
in sequence. And the effects are applied based in the table:

![image](https://github.com/LaercioSant0s/M_ortal_Comba_t/assets/127317610/564f4b24-0d1f-47d4-9982-74945e57cbab)

Example:

P1 "CCA" and P2 "AZ"

![image](https://github.com/LaercioSant0s/M_ortal_Comba_t/assets/127317610/e08f2850-2bc2-47ac-9df2-c3bb29a40148)

Attacks compared: "CA", "CZ", "A " (in the [ | ] structure) 

> Life: <br>
"CA" is a negative number in the table, P1 lose -16 life points <br>
"CZ" is a positive number in the table, P2 lose -16 life points <br>
"A " is a positive number in the table, P2 lose -20 life points <br>

> Stamina: <br>
P1 (3 attacks) = -75 stamina points <br>
P2 (2 attacks) = -50 stamina points + (" ") recovers 25 stamina points

<br>

P1 life (1000 - 16), P1 stamina (1000 - 75) <br>
P2 life (1000 - 36), P2 stamina (1000 - 25) <br>

<br>

![image](https://github.com/LaercioSant0s/M_ortal_Comba_t/assets/127317610/9d663fcc-48d6-44f9-958b-51b814ab6f47)

## Combos
The best way to start the battle because you can only perform them when 
your stamina is greater than 750 otherwise an stamina message will
show up and your combo will be ignored.

![image](https://github.com/LaercioSant0s/M_ortal_Comba_t/assets/127317610/a3061a2d-9f9b-4029-bb36-52c70652735b)

You can only perform the following combos:

![image](https://github.com/LaercioSant0s/M_ortal_Comba_t/assets/127317610/1ec48a90-04b3-487d-80de-5be81d93a152)

## Additional features

Multiplier, when your stamina is: 

> Above 750, normal damage to your opponent; <br>
> Above 500, x2 damage to your opponent; <br>
> Above 250, x3 damage to your opponent; <br>
> Under 250, x4 damage to your opponent. <br>




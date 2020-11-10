/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** 
*/

int my_is_prime2(int nb)
{
    int i = 2;

    while (i < nb) {
        if (nb % i == 0)
            return (0);
        nb % i;
        i++;
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    while (my_is_prime2(nb) != 1) {
        nb++;
    }
    return (nb);
}

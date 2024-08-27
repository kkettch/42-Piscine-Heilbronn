/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:45:22 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/22 17:14:54 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int is_sep(char *charset, char str)
{
    int index;
    index = 0;    while (charset[index])
    {        if (str == charset[index])
            return (true);        index++;
    }    return (false);
}
int counter(char *str, char *charset){
    int index_str;    int count_words;
    int is_word;
    is_word = false;    index_str = 0;
    count_words = 0;    while (str[index_str])
    {        if (is_word == false && !is_sep(charset, str[index_str]))
        {            is_word = true;
            count_words++;        }
        if (is_word == true && is_sep(charset, str[index_str]))            is_word = false;
        index_str++;    }
    return (count_words);}
int length_counter(char *str, char *charset, int *count_length)
{    int count;
    count = 0;
    while (str[*count_length])    {
        if (!is_sep(charset, str[*count_length]))        {
            (*count_length)++;            count++;
        }        else
        {            (*count_length)++;
            break ;        }
    }    return (count);
}
void    fill_result(char *str, char *charset, char **result){
    int index1_res;    int index2_res;
    int index_str;
    index1_res = 0;    index_str = 0;
    while (str[index_str])    {
        index2_res = 0;        while (!is_sep(charset, str[index_str]) && str[index_str])
        {            result[index1_res][index2_res++] = str[index_str++];
            if (is_sep(charset, str[index_str]) || str[index_str] == '\0')
                result[index1_res++][index2_res] = '\0';        }
        index_str++;    }
    result[counter(str, charset)] = NULL;}
char    **ft_split(char *str, char *charset)
{    int     index;
    int     count_length;    int     count_words;
    int     temp_length;    char    **result;

    count_words = counter(str, charset);    result = (char **)malloc((count_words + 1) * sizeof(char *));
    if (result == NULL)        return (NULL);
    count_length = 0;    index = 0;
    while (count_words > 0)    {
        temp_length = length_counter(str, charset, &count_length);        if (temp_length == 0)
            continue ;        result[index] = (char *)malloc((temp_length + 1) * sizeof(char));
        if (result[index++] == NULL)            return (NULL);
        count_words--;    }
    fill_result(str, charset, result);    return (result);
}
#include <stdio.h>

int main(void)
{
	char **result;
	result = ft_split("h", "");
	for (char **ptr = result; *ptr != NULL; ptr++)
	{
        if (*ptr != NULL)
            printf("%s\n", *ptr);
    }
	return (0);
}

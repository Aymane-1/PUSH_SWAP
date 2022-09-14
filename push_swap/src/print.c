/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:37:26 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 12:01:51 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    print_stacks(t_frame *frame)
// {
//     t_stack *temp = frame->a;
//     t_stack *head = frame->a;
//     t_stack *temp1 = frame->b;
//     t_stack *head1 = frame->b;

//     printf("\nstack a :\n");
//     while(1)
//     {
//         printf("%ld   ", temp->num);
//         temp = temp->next;
//         if(temp == head)
//             break;
//     }

//     printf("\nstack b :\n");
//     if (!temp1)
//         printf("    EMPTY!  |_| \n");
//     else
//         while(1)
//         {
//             printf("%5ld", temp1->num);
//             temp1 = temp1->next;
//             if(temp1 == head1)
//                 break;
//         }
//     printf("\n");
// }

// void print_list(t_frame *frame) 
// {
//     t_stack *temp = frame->a;
//     t_stack *head = frame->a;
//     t_stack *temp1 = frame->b;
//     t_stack *head1 = frame->b;

//     printf("\nstack a :\n");
//     while(1)
//     {
//         printf("%5ld", temp->num);
//         temp = temp->next;
//         if(temp == head)
//             break;
//     }

//     printf("\n");
//     printf("stack b :\n");
//     if (!temp1)
//         printf("    EMPTY!  |_| \n");
//     else
//         while(1)
//         {
//             printf("%5ld", temp1->num);
//             temp1 = temp1->next;
//             if(temp1 == head1)
//                 break;
//         }
//     printf("\n");
//     printf("pair :\n");
//     while(1)
//     {
//         printf("%5ld", temp1->pair);
//         temp1 = temp1->next;
//         if(temp1 == head1)
//             break;
//     }
//     printf("\n");
//     printf("index of pair :\n");
//     while(1)
//     {
//         printf("%5d", temp1->ind_of_pair);
//         temp1 = temp1->next;
//         if(temp1 == head1)
//             break;
//     }
//     printf("\n");
//     printf("moves :\n");
//     while(1)
//     {
//         printf("%5d", temp1->moves);
//         temp1 = temp1->next;
//         if(temp1 == head1)
//             break;
//     }
//     printf("\n");
//     printf("smallest of a: ");
//     printf("%5ld", frame->a->smallest);
//     printf("\n");
//     printf("biggest of a:  ");
//     printf("%5ld", frame->a->biggest);
//     printf("\n");
//     printf("smallest of b: ");
//     printf("%5ld", frame->b->smallest);
//     printf("\n");
//     printf("biggest of b:  ");
//     printf("%5ld", frame->b->biggest);
//     printf("\n");
//     printf("lowest :\n");
//     while(1)
//     {
//         printf("%5d", temp1->lowest);
//         temp1 = temp1->next;
//         if(temp1 == head1)
//             break;
//     } 
// }

// void print_lis_and_mark(t_frame* frame)
// {
//     t_stack *temp = frame->a;
//     t_stack *head = frame->a;
//     t_stack *temp1 = frame->a;
//     t_stack *head1 = frame->a;

//     printf("lis  : ");
//     while(1)
//     {
//         printf("%5d", temp->lis);
//         temp = temp->next;
//         if(temp == head)
//             break;
//     }

//     printf("\n");
//     printf("mark : ");
//         while(1)
//         {
//             printf("%5d", temp1->mark);
//             temp1 = temp1->next;
//             if(temp1 == head1)
//                 break;
//         }
//     printf("\n");
// }
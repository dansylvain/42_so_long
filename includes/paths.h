/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:45:15 by dan               #+#    #+#             */
/*   Updated: 2024/01/14 17:03:59 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

typedef enum t_sprites_id
{
	S_GROUND_00,
	S_GROUND_01,
	S_ROCK_00,
	S_ROCK_01,
	S_ROCK_10,
	S_ROCK_11,
	S_ROCK_20,
	S_ROCK_21,
	S_ROCK_30,
	S_ROCK_31,
	S_ROCK_40,
	S_ROCK_41,
	S_CRYSTAL_00,
	S_CRYSTAL_01,
	S_CRYSTAL_10,
	S_CRYSTAL_11,
	S_CRYSTAL_20,
	S_CRYSTAL_21,
	S_CRYSTAL_30,
	S_CRYSTAL_31,
	S_CRYSTAL_40,
	S_CRYSTAL_41,
	S_EXP_0_0,
	S_EXP_0_1,
	S_EXP_0_2,
	S_EXP_0_3,
	S_EXP_0_4,
	S_EXP_0_5,
	S_EXP_0_6,
	S_EXP_0_7,
	S_EXP_0_8,
	S_EXP_0_9,
	S_EXP_1_0,
	S_EXP_1_1,
	S_EXP_1_2,
	S_EXP_1_3,
	S_EXP_1_4,
	S_EXP_1_5,
	S_EXP_1_6,
	S_EXP_1_7,
	S_EXP_1_8,
	S_EXP_1_9,
	S_EXP_2_0,
	S_EXP_2_1,
	S_EXP_2_2,
	S_EXP_2_3,
	S_EXP_2_4,
	S_EXP_2_5,
	S_EXP_2_6,
	S_EXP_2_7,
	S_EXP_2_8,
	S_EXP_2_9,
	S_EXP_3_0,
	S_EXP_3_1,
	S_EXP_3_2,
	S_EXP_3_3,
	S_EXP_3_4,
	S_EXP_3_5,
	S_EXP_3_6,
	S_EXP_3_7,
	S_EXP_3_8,
	S_EXP_3_9,
	S_EXP_4_0,
	S_EXP_4_1,
	S_EXP_4_2,
	S_EXP_4_3,
	S_EXP_4_4,
	S_EXP_4_5,
	S_EXP_4_6,
	S_EXP_4_7,
	S_EXP_4_8,
	S_EXP_4_9,
	S_CHAR_SPRITE
}	t_sprites_id;

# define GROUND_00		"assets/0.xpm"
# define GROUND_01		"assets/1.xpm"
# define ROCK_00		"assets/2.xpm"
# define ROCK_01		"assets/3.xpm"
# define ROCK_10		"assets/4.xpm"
# define ROCK_11		"assets/5.xpm"
# define ROCK_20		"assets/6.xpm"
# define ROCK_21		"assets/7.xpm"
# define ROCK_30		"assets/8.xpm"
# define ROCK_31		"assets/9.xpm"
# define ROCK_40		"assets/10.xpm"
# define ROCK_41		"assets/11.xpm"
# define CRYSTAL_00		"assets/12.xpm"
# define CRYSTAL_01		"assets/13.xpm"
# define CRYSTAL_10		"assets/14.xpm"
# define CRYSTAL_11		"assets/15.xpm"
# define CRYSTAL_20		"assets/16.xpm"
# define CRYSTAL_21		"assets/17.xpm"
# define CRYSTAL_30		"assets/18.xpm"
# define CRYSTAL_31		"assets/19.xpm"
# define CRYSTAL_40		"assets/20.xpm"
# define CRYSTAL_41		"assets/21.xpm"
# define EXP_0_0		"assets/22.xpm"
# define EXP_0_1		"assets/23.xpm"
# define EXP_0_2		"assets/24.xpm"
# define EXP_0_3		"assets/25.xpm"
# define EXP_0_4		"assets/26.xpm"
# define EXP_0_5		"assets/27.xpm"
# define EXP_0_6		"assets/28.xpm"
# define EXP_0_7		"assets/29.xpm"
# define EXP_0_8		"assets/30.xpm"
# define EXP_0_9		"assets/31.xpm"
# define EXP_1_0		"assets/32.xpm"
# define EXP_1_1		"assets/33.xpm"
# define EXP_1_2		"assets/34.xpm"
# define EXP_1_3		"assets/35.xpm"
# define EXP_1_4		"assets/36.xpm"
# define EXP_1_5		"assets/37.xpm"
# define EXP_1_6		"assets/38.xpm"
# define EXP_1_7		"assets/39.xpm"
# define EXP_1_8		"assets/40.xpm"
# define EXP_1_9		"assets/41.xpm"
# define EXP_2_0		"assets/42.xpm"
# define EXP_2_1		"assets/43.xpm"
# define EXP_2_2		"assets/44.xpm"
# define EXP_2_3		"assets/45.xpm"
# define EXP_2_4		"assets/46.xpm"
# define EXP_2_5		"assets/47.xpm"
# define EXP_2_6		"assets/48.xpm"
# define EXP_2_7		"assets/49.xpm"
# define EXP_2_8		"assets/50.xpm"
# define EXP_2_9		"assets/51.xpm"
# define EXP_3_0		"assets/52.xpm"
# define EXP_3_1		"assets/53.xpm"
# define EXP_3_2		"assets/54.xpm"
# define EXP_3_3		"assets/55.xpm"
# define EXP_3_4		"assets/56.xpm"
# define EXP_3_5		"assets/57.xpm"
# define EXP_3_6		"assets/58.xpm"
# define EXP_3_7		"assets/59.xpm"
# define EXP_3_8		"assets/60.xpm"
# define EXP_3_9		"assets/61.xpm"
# define EXP_4_0		"assets/62.xpm"
# define EXP_4_1		"assets/63.xpm"
# define EXP_4_2		"assets/64.xpm"
# define EXP_4_3		"assets/65.xpm"
# define EXP_4_4		"assets/66.xpm"
# define EXP_4_5		"assets/67.xpm"
# define EXP_4_6		"assets/68.xpm"
# define EXP_4_7		"assets/69.xpm"
# define EXP_4_8		"assets/70.xpm"
# define EXP_4_9		"assets/71.xpm"
# define CHAR_SPRITE	"assets/73.xpm"

#endif
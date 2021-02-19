#include "c3d.h"

int		draw_map(t_struct *j)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	j->i.y = 0;
	j->i.x = 0;
	while (k != j->d.ymap)
	{
		if ((ft_strchr("0 ", j->d.jmap[k][i]) + 1) && !(j->i.col = 0))
			big_pp(j);
		else if (j->d.jmap[k][i] == '1' && (j->i.col = 0xff0000))
			big_pp(j);
		else if (j->d.jmap[k][i] == '2' && (j->i.col = 0xff))
			big_pp(j);
		else if (j->d.jmap[k][i] && (ft_strchr("NEWS", j->d.jmap[k][i]) + 1))
			ppos(j, i, k);
		if (!j->d.jmap[k][++i] && !(i = 0))
		{
			j->i.y += 32;
			k++;
			j->i.x = 0;
		}
	}
	return (1);
}

void	big_pp(t_struct *j)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	x = 0;
	j->d.tx = (int)floor(j->d.px / 32);
	j->d.ty = (int)floor(j->d.py / 32);
	while (y < 32)
	{
		i = x;
		while (i < 32)
			small_pp(&j->i, j->i.x + i++, j->i.y + y);
		y++;
	}
	if ((j->d.px * j->d.py) && (j->d.tx == floor(j->i.x / 32)) &&
	(j->d.ty == floor(j->i.y / 32)))
	{
		ppp(j);
		return ;
	}
	j->i.x += 32;
}

void	ppp(t_struct *j)
{
	int		x;
	int		y;

	y = -3;
	j->i.col = 0xff00;
	while (y < 4)
	{
		x = -3;
		while (x < 4)
			small_pp(&j->i, j->d.px + x++, j->d.py + y);
		y++;
	}
	// j->d.rx = j->d.px;
	// j->d.ry = j->d.py;
	// while (j->d.jmap[(int)floor(j->d.rx / 32)][(int)floor(j->d.rx / 32)] != '1')
	// {
	// 	if (!(j->d.rx * j->d.ry))
	// 		break ;
	// 	j->d.rx -= cos(j->d.pa);
	// 	j->d.ry -= sin(j->d.pa);
	// }
	j->i.x += 32;
}
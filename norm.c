t_point	ret_x_y(int x, int y)
{
	t_point	set;

	set.x = x;
	set.y = y;
	return (set);
}
t_imgs	while_y(t_imgs ret, t_vars vars, t_point e_i, t_point y_x)
{
	while (vars.map[e_i.x][++e_i.y] != '\0')
	{
		if (vars.map[e_i.x][e_i.y + 1] == '\0')
			break ;
		y_x = ret_x_y(y_x.x + 32, y_x.y + 16);
		ret = set_frame(vars, ret, e_i, y_x);
	}
	return (ret);
}
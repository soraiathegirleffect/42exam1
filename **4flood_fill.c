
typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void  ffill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x || tab[row][col] != target)
		return;
	/*begin.y=row, begin.x=col; The function won't fill diagonally, not negative, not less than size
	the limiter of the zone tab[row][col]: "delimitated horizontally and vertically by other characters*/

	tab[row][col] = 'F';
	ffill(tab, size, target, row - 1, col);
	ffill(tab, size, target, row + 1, col);
	ffill(tab, size, target, row, col - 1);
	ffill(tab, size, target, row, col + 1);

	/*// Recursively fill the surrounding spaces*/
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	ffill(tab, size, target, begin.y, begin.x);
}




//orrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr



typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

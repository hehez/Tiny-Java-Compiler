/*
 * Syntax error test 15:
 * Line 7: incomplete parameters in method declaration (end on a comma)
 *
 */
public class Err15
{
    static int method( int x, )
    {
	int i = 0;
	return i + 1;
    }

    public static void main( String[] args )
    {
	int i = 0;
	int j = 0;

	j = 9 + i * 8;

	return;
    }
}

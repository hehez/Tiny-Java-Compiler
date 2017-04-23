/*
 * Syntax error test 4:
 * Line:  missing main method name
 *
 */
public class Err4
{
    public static void ( String[] args )
    {
	int i = 0;
	int j = 0;

	j = 9 + i * 8;

	return;
    }
}

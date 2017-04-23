/*
 * Syntax error test 17 (grad only): 
 * Line 13:  missing array size in array construction
 *
 */
public class Err17
{
    public static void main( String[] args )
    {
	float[] vector = null;
 
	vector = new float[];
	return;
    }
}

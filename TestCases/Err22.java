/*
 * Syntax error test 22 (grad only): 
 * Line 12:  missing array size in array construction
 *
 */
public class Err22
{
    public static void main( String[] args )
    {
	float[] vector = null;
 
	vector = new float;
	return;
    }
}

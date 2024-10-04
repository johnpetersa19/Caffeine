#include "ratio.h"

/**
 * This function calculates the extraction ratio of a coffee.
 *
 * @param ground_amount Ground coffee weight
 * @param extract_amount Extracted coffee weight
 *
 * @return Ratio as the denominator of a fraction with numerator equal to 1
 */
double ratio(double ground, double extract)
{
    return extract / ground;
}

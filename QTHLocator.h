/*
 * QTH Locator
 */

// Calculate the Grid Square from the latitude and longitude

String CalculateGridSquare(float latitude, float longtitude) {
  float lat_2, calc_long_2, calc_lat_2, calc_long_3;
  int grid_long_1, grid_lat_1, grid_long_2, grid_lat_2, grid_long_3, grid_lat_3;

  char A_Z[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char grid[6];                                           // Array of characters for the Grid Square function

  grid_lat_1 = int((latitude + 90) / 10);                 // Calculate the first 2 characters of the Grid Square
  grid_long_1 = int((longtitude + 180) / 20);
    
  lat_2 = (latitude + 90) - (grid_lat_1 * 10);            // Calculate the next 2 digits of the Grid Square
  grid_lat_2 = int(lat_2);
  calc_long_2 = (longtitude + 180) - (grid_long_1 * 20); 
  grid_long_2 = int(calc_long_2 / 2);
  
  grid_lat_3 = int((lat_2 - int(lat_2)) / .0416665);      // Calculate the last 2 characters of the Grid Square
  calc_long_3 = calc_long_2 - (grid_long_2 * 2);  
  grid_long_3 = int(calc_long_3 / .083333);
  
  grid[0] = A_Z[grid_long_1];                             // Here's the first 2 characters of Grid Square - place into array
  grid[1] = A_Z[grid_lat_1];
  grid[2] = (grid_long_2 + 48);                           // The second set of the grid square
  grid[3] = (grid_lat_2 + 48);
  grid[4] = A_Z[grid_long_3];                             // The final 2 characters
  grid[5] = A_Z[grid_lat_3];
  
  return grid;
}

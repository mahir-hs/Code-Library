for (k = 0; k < nV; k++) {
  for (i = 0; i < nV; i++) {
    for (j = 0; j < nV; j++) {
      if (matrix[i][k] + matrix[k][j] < matrix[i][j])
        matrix[i][j] = matrix[i][k] + matrix[k][j];
    }
  }
}

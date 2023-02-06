typedef struct Vector2{
    double x, y;
    double origin;
} Vector2;

int isZero(Vector2 *vector);
Vector2 *VectorAddition(Vector2 *vector);
Vector2 *VectorSubtraction(Vector *vector);
Vector2 *VectorScalar(Vector2 *vector);
Vector2 *Normalise(Vector2 *vector);

import numpy as np
import matplotlib.pyplot as plt

from transformations import rotate_vector, transform_shape


def main():
    original_vector = [1, 0]
    angle = 45
    rotated_vec = rotate_vector(original_vector, angle)

    print(f"Original vector: {original_vector}")
    print(f"Rotated vector by {angle}°: {rotated_vec}\n")

    square = np.array([
        [0, 0],
        [1, 0],
        [1, 1],
        [0, 1],
        [0, 0]
    ])

    scale_x = 2.0
    scale_y = 1.5
    shear_x = 0.5

    transformed_square = transform_shape(square, scale_x, scale_y, shear_x)

    fig, ax = plt.subplots()

    ax.plot(square[:, 0], square[:, 1], label="Original Square", marker='o')

    ax.plot(transformed_square[:, 0], transformed_square[:, 1], label="Transformed Square", marker='x')

    ax.set_aspect('equal', adjustable='box')
    ax.set_title("Scale + Shear Transformation")
    ax.legend()
    ax.grid(True)

    plt.show()


if __name__ == "__main__":
    main()

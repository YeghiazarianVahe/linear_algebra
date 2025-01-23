import numpy as np


def rotate_vector(vector, angle_degrees):
    angle_radians = np.deg2rad(angle_degrees)

    rotation_matrix = np.array([
        [np.cos(angle_radians), -np.sin(angle_radians)],
        [np.sin(angle_radians), np.cos(angle_radians)]
    ])

    vector = np.array(vector, dtype=float)

    rotated_vector = rotation_matrix @ vector
    return rotated_vector


def transform_shape(points, scale_x=1.0, scale_y=1.0, shear_x=0.0):
    scale_matrix = np.array([
        [scale_x, 0.0],
        [0.0, scale_y]
    ])

    shear_matrix = np.array([
        [1.0, shear_x],
        [0.0, 1.0]
    ])

    transformation_matrix = shear_matrix @ scale_matrix

    points = np.array(points, dtype=float)

    transformed_points = points @ transformation_matrix.T

    return transformed_points

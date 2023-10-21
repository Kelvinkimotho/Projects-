package org.example;

public class employee {
    int id;
    String name;

    // bellow is a constructor
    public employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    // selection sort function
    public static void selectionSort(employee[] array, int low, int high) {
        for (int i = low; i < high; i++) {
            int minIndex = i;
            for (int j = i + 1; j <= high; j++) {
                if (array[j].id < array[minIndex].id) {
                    minIndex = j;
                }
            }
            employee temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }


    // A function for performing the binary search
    public static int binarySearch(employee[] array, int low, int high, int target) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            if (array[mid].id == target) {
                return mid;
            }
            if (array[mid].id < target) {
                return binarySearch(array, mid + 1, high, target);
            }
            return binarySearch(array, low, mid - 1, target);
        }
        return -1;
    }

}




import java.io.File;

public class Main {
    public static void main(String[] args) {
        // The old main file
        File oldFile = new File("mainFile.txt");

        try {
            oldFile.createNewFile();
        } catch (Exception e) {
            System.out.println("error");
        }


        // The temporary file that will become the new main file
        File tempFile = new File("tempFile.txt");
        try {
            tempFile.createNewFile();
        } catch (Exception e) {
            System.out.println("error");
        }

        // Check if the old main file exists before renaming and deleting
        if (oldFile.exists()) {
            // Delete the old main file
            if (oldFile.delete()) {
                System.out.println("Old main file deleted successfully.");

                // Rename the temp file to main file
                if (tempFile.renameTo(oldFile)) {
                    System.out.println("Temp file renamed to main file successfully.");
                } else {
                    System.out.println("Failed to rename the temp file.");
                }
            } else {
                System.out.println("Failed to delete the old main file.");
            }
        } else {
            System.out.println("Old main file does not exist.");
        }
    }
}

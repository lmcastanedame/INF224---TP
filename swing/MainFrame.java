import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class MainFrame extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JTextField inputField;
    private JToolBar toolBar;
    private JMenuBar menuBar;
    private JMenu menu;
    private final String serverAddress = "localhost"; // or the IP address of your server
    private final int serverPort = 3331; // the port number your server is listening on

    public MainFrame() {
        // Create components
        textArea = new JTextArea(20, 30);
        inputField = new JTextField(20);
        toolBar = new JToolBar();
        menuBar = new JMenuBar();
        menu = new JMenu("Commands");
        configureWindow();

        // Create actions
        Action createPhotoAction = new AbstractAction("Create Photo") {
            public void actionPerformed(ActionEvent e) {
                // Assume the input format is "name pathname latitude longitude"
                sendCommandToServer("CREATE_PHOTO " + inputField.getText());
            }
        };

        Action createVideoAction = new AbstractAction("Create Video") {
            public void actionPerformed(ActionEvent e) {
                // Assume the input format is "name pathname duration"
                sendCommandToServer("CREATE_VIDEO " + inputField.getText());
            }
        };

        Action helpAction = new AbstractAction("Help") {
            public void actionPerformed(ActionEvent e) {
                displayHelp();
            }
        };

        Action searchAction = new AbstractAction("Search") {
            public void actionPerformed(ActionEvent e) {
                sendCommandToServer("SEARCH " + inputField.getText());
            }
        };

        Action playAction = new AbstractAction("Play") {
            public void actionPerformed(ActionEvent e) {
                sendCommandToServer("PLAY " + inputField.getText());
            }
        };

        Action exitAction = new AbstractAction("Exit") {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };

        // Add actions to toolbar and menu
        toolBar.add(inputField);
        toolBar.addSeparator();

        toolBar.add(searchAction);
        toolBar.add(createPhotoAction);
        toolBar.add(createVideoAction);
        toolBar.add(helpAction);
        toolBar.add(playAction);
        toolBar.add(exitAction);

        menu.add(searchAction);
        menu.add(createPhotoAction);
        menu.add(createVideoAction);
        menu.add(helpAction);
        menu.add(playAction);
        menu.add(exitAction);

        // Add menu to menu bar
        menuBar.add(menu);

        // Add toolbar and menu bar to the window
        this.add(toolBar, BorderLayout.NORTH);
        this.setJMenuBar(menuBar);

        // Add the text area to the window
        this.add(new JScrollPane(textArea), BorderLayout.CENTER);

        // Configure the window
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.pack();
        this.setVisible(true);
    }

    private void displayHelp() {
        JOptionPane.showMessageDialog(this, "Available Commands:\n" +
                "CREATE_PHOTO <name> <pathname> <latitude> <longitude> - Create a new photo object.\n" +
                "CREATE_VIDEO <name> <pathname> <duration> - Create a new video object.\n" +
                "SEARCH <name> - Search for a multimedia object by name and display its details.\n" +
                "PLAY <name> - Play a multimedia object by name.\n" +
                "quit - Exit the client.\n" +
                "help - Display this help message.", "Help", JOptionPane.INFORMATION_MESSAGE);
    }

    private void configureWindow() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.pack();
        this.setVisible(true);
    }

    private void sendCommandToServer(String command) {
        new Thread(() -> {
            try (Socket socket = new Socket(serverAddress, serverPort);
                 PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                 BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
                 
                // Send the command to the server
                out.println(command);
    
                // Clear the input field on the Event Dispatch Thread (EDT)
                SwingUtilities.invokeLater(() -> inputField.setText(""));
                
                // Read server responses line by line and update GUI in real-time
                String line;
                while (true) {
                    if (in.ready()) {
                        line = in.readLine();
                        if (line == null || line.isEmpty()) {
                            break; // Exit loop if end of stream or empty line is detected
                        }
                        String response = line + "\n";
                        SwingUtilities.invokeLater(() -> textArea.append(response));
                    }
                }
            } catch (Exception e) {
                SwingUtilities.invokeLater(() -> textArea.append("Error communicating with the server: " + e.getMessage() + "\n"));
            }
        }).start();
    }
    
    

    public static void main(String[] args) {
        // For MacOSX users
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        SwingUtilities.invokeLater(() -> new MainFrame());
    }
}

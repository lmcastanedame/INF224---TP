import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class MainFrame extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JToolBar toolBar;
    private JMenuBar menuBar;
    private JMenu menu;

    public MainFrame() {
        // Create components
        textArea = new JTextArea(20, 30);
        toolBar = new JToolBar();
        menuBar = new JMenuBar();
        menu = new JMenu("Menu");

        // Create actions
        Action action1 = new AbstractAction("Add line 1") {
            public void actionPerformed(ActionEvent e) {
                textArea.append("Line added by button 1\n");
            }
        };

        Action action2 = new AbstractAction("Add line 2") {
            public void actionPerformed(ActionEvent e) {
                textArea.append("Line added by button 2\n");
            }
        };

        Action action3 = new AbstractAction("Exit") {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };

        // Add actions to toolbar and menu
        toolBar.add(action1);
        toolBar.add(action2);
        toolBar.add(action3);
        menu.add(action1);
        menu.add(action2);
        menu.add(action3);

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

    public static void main(String[] args) {
        // For MacOSX users
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new MainFrame();
            }
        });
    }
}
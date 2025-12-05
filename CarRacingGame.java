import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

public class CarRacingGame extends JPanel implements ActionListener, KeyListener {
    private int carX = 200, carY = 350; // Car position
    private int obsX, obsY = -100; // Obstacle position
    private int score = 0;
    private Timer timer;
    private boolean gameOver = false;
    
    public CarRacingGame() {
        setFocusable(true);
        addKeyListener(this);
        timer = new Timer(100, this);
        timer.start();
        Random rand = new Random();
        obsX = 160 + rand.nextInt(200);
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(Color.GRAY);
        
        // Draw Road
        g.setColor(Color.WHITE);
        g.drawLine(150, 0, 150, 500);
        g.drawLine(350, 0, 350, 500);
        
        // Draw Player Car
        g.setColor(Color.GREEN);
        g.fillRect(carX, carY, 40, 60);

        // Draw Obstacle Car
        g.setColor(Color.RED);
        g.fillRect(obsX, obsY, 40, 60);
        
        // Display Score
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 20));
        g.drawString("Score: " + score, 10, 20);
        
        // Game Over Message
        if (gameOver) {
            g.setColor(Color.RED);
            g.setFont(new Font("Arial", Font.BOLD, 30));
            g.drawString("GAME OVER!", 150, 200);
        }
    }

    public void actionPerformed(ActionEvent e) {
        if (!gameOver) {
            obsY += 10; // Move obstacle down

            // Reset obstacle position if it moves off-screen
            if (obsY > 500) {
                obsY = -100;
                obsX = 160 + new Random().nextInt(200);
                score++;
            }

            // Check for collision
            if (carX < obsX + 40 && carX + 40 > obsX && carY < obsY + 60 && carY + 60 > obsY) {
                gameOver = true;
                timer.stop();
            }
            repaint();
        }
    }

    public void keyPressed(KeyEvent e) {
        if (!gameOver) {
            if (e.getKeyCode() == KeyEvent.VK_LEFT && carX > 160) {
                carX -= 50;
            }
            if (e.getKeyCode() == KeyEvent.VK_RIGHT && carX < 310) {
                carX += 50;
            }
        }
    }

    public void keyReleased(KeyEvent e) {}

    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        JFrame frame = new JFrame("Car Racing Game");
        CarRacingGame game = new CarRacingGame();
        frame.add(game);
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

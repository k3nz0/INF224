import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.Dimension;

public class RemoteControl
{
	private static final long serialVersionUID = 1L;

	/** Will contain input to be sent throught sockets */
	private static JTextArea textArea;
	
	/** Will contain results in html format */	
	private static JLabel results;

	private int width, height;

	private Client client;
	

	public RemoteControl(Client client, int width, int height) {
		this.client = client;
		this.width = width;
		this.height = height;
	}

	public void display()
	{
		JFrame frame = new JFrame("Remote control");
		// Quit the program when the window is closed
		
		frame.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				System.exit(0);
			}
		});

		textArea = new JTextArea(40, 70);
		results = new JLabel("Result :");

		SearchAction searchAction = new SearchAction("Search");
		PlayAction playAction = new PlayAction("Play");
		CloseAction closeAction = new CloseAction("Close");
		ListAction listAction = new ListAction("ListAll");

		JButton searchButton = new JButton(searchAction);
		JButton playButton = new JButton(playAction);
		JButton closeButton = new JButton(closeAction);
		JButton listButton = new JButton(listAction);
		
		JScrollPane scrollPane = new JScrollPane(textArea);
		JPanel panel = new JPanel();

		JMenuBar menuBar = new JMenuBar();
		JMenu menu = new JMenu("Menu");
		
		menu.add(new JMenuItem(searchAction));
		menu.add(new JMenuItem(playAction));
		menu.add(new JMenuItem(closeAction));
		menu.add(new JMenuItem(listAction));
		
		menuBar.add(new JMenuItem(searchAction));
		menuBar.add(new JMenuItem(playAction));
		menuBar.add(new JMenuItem(closeAction));
		menuBar.add(new JMenuItem(listAction));

		menuBar.add(menu);

		frame.setJMenuBar(menuBar);

		panel.add(searchButton);
		panel.add(playButton);
		panel.add(closeButton);
		panel.add(listButton);

		frame.add(panel, BorderLayout.EAST);
		frame.add(scrollPane, BorderLayout.CENTER);
		frame.add(results, BorderLayout.SOUTH);

		frame.setPreferredSize(new Dimension(width, height));
		frame.pack();
		frame.setVisible(true);
	}

	String parseResult(String result) {
		String response = "<html>Result : <br>" + result.replace("||", "<br>") + "</html>";
		return response;
	}

	/**
	 * Calls client to send a SEARCH request to the server.
	 */
	class SearchAction extends AbstractAction {

		private static final long serialVersionUID = 201811031717L;

		public SearchAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e)
		{
			String response = client.send("SEARCH " + textArea.getText());
			// response = "<html>Result : <br>" + response.replace("||", "<br>") + "</html>";
			response = parseResult(response);
			results.setText(response);
		}
		
	}

	/**
	 * Calls client to send a PLAY request to the server.
	 */
	
	class PlayAction extends AbstractAction {

		private static final long serialVersionUID = 201811031718L;

		public PlayAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String response = client.send("PLAY " + textArea.getText());
			response = "<html>Result : <br>" + response.replace("||", "<br>") + "</html>";
			results.setText(response);
		}
		
	}

	/**
	* Calls client to send a CLOSE request to the server.
	*/
	
	class CloseAction extends AbstractAction {
		private static final long serialVersionUID = 201811031719L;

		public CloseAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
			
		}
		
	}
	class ListAction extends AbstractAction {
		private static final long serialVersionUID = 201811031720L;

		public ListAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String response = client.send("LIST");
			response = "<html>Result : <br>" + response.replace("||", "<br>") + "</html>";
			results.setText(response);			
		}
		
	}


}


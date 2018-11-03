import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.Dimension;

public class RemoteControl
{
	private static final long serialVersionUID = 1L;
	/** Ccontains input to be sent throught sockets */
	private static JTextArea textArea;
	/** Contains results in html format */	
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

		textArea = new JTextArea(40, 40);
		results = new JLabel("Result :");

		SearchAction searchAction = new SearchAction("Search");
		PlayAction playAction = new PlayAction("Play");
		ListAction listAction = new ListAction("ListAll");
		CloseAction closeAction = new CloseAction("Close");

		JButton searchButton = new JButton(searchAction);
		JButton playButton = new JButton(playAction);
		JButton listButton = new JButton(listAction);
		JButton closeButton = new JButton(closeAction);
		
		JScrollPane scrollPane = new JScrollPane(textArea);
		JPanel panel = new JPanel();
		
		JMenuBar menuBar = new JMenuBar();
		JMenu menu = new JMenu("Menu");
		
		menu.add(new JMenuItem(searchAction));
		menu.add(new JMenuItem(playAction));
		menu.add(new JMenuItem(listAction));
		menu.add(new JMenuItem(closeAction));
		
		menuBar.add(new JMenuItem(searchAction));
		menuBar.add(new JMenuItem(playAction));
		menuBar.add(new JMenuItem(listAction));
		menuBar.add(new JMenuItem(closeAction));

		menuBar.add(menu);

		frame.setJMenuBar(menuBar);

		searchButton.setPreferredSize(new Dimension(100, 30));
		playButton.setPreferredSize(new Dimension(100, 30));
		listButton.setPreferredSize(new Dimension(100, 30));
		closeButton.setPreferredSize(new Dimension(100, 30));
		
		panel.setPreferredSize(new Dimension(120, 200));

		panel.add(searchButton);
		panel.add(playButton);
		panel.add(closeButton);
		panel.add(listButton);


		frame.add(panel, BorderLayout.WEST);
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
	 * Calls client to send a SEARCH request to the server and shows the result in results JLabel
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
			response = parseResult(response);
			results.setText(response);
		}
		
	}

	/**
	 * Calls client to send a PLAY request to the server and shows the result in results JLabel
	 */
	
	class PlayAction extends AbstractAction {

		private static final long serialVersionUID = 201811031718L;

		public PlayAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String response = client.send("PLAY " + textArea.getText());
			response = parseResult(response);
			results.setText(response);
		}
		
	}
	/**
	* Calls client to send a LIST request to the server and shows the result in results JLabel
	*/

	class ListAction extends AbstractAction {
		private static final long serialVersionUID = 201811031720L;

		public ListAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String response = client.send("LIST");
			response = parseResult(response);
			results.setText(response);			
		}
		
	}

	/**
	* Close Java execution
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



}


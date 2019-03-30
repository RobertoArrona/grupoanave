INTRODUCTION
------------

Drupal 7.42 release breaks autocomplete functionality on certain unusual server
configurations that block direct access to Drupal's index.php file.

This module fixes autocomplete functionality on environments with restricted
access to index.php.

Don't use this module if your server doesn't block direct access
to Drupal's index.php file.


INSTALLATION
------------

Install as usual, see
https://drupal.org/documentation/install/modules-themes/modules-7 for further
information.


TROUBLESHOOTING
---------------

Autocomplete Unblock module doesn't provide any visible functions to the user on its own, it
just implements hook_url_outbound_alter() to fix autocomplete functionality
on environments with restricted access to index.php.


MAINTAINERS
-----------

Current maintainers:

 * Igor Plity (https://www.drupal.org/user/339552)

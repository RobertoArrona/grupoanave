<?php
/**
 * @file
 * Este es un archivo que pinta el nombre del usuario y su rol.
 */
$delete_roles = array(
  'anonymous user', 
  'authenticated user', 
  'administrator', 
);
$my_roles = $elements['#account']->roles;
$first_role = '';
foreach($my_roles as $my_role) {
  if ( !in_array($my_role, $delete_roles) ) {
    $first_role = ucwords($my_role);
    break;
  }
}

?>
<span class="nombre"><?php print render($elements['field_first_name']);?></span> <span class="apellidos"><?php print render($elements['field_last_name']);?></span> - <span class="role"><?php print $first_role;?></span>
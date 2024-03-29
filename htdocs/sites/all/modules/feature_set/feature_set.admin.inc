<?php 

/**
 * Define the administration form
 */ 
function feature_set_admin_form($form, &$form_state, $install_state = NULL) {
  $featuresets = feature_set_get_featuresets($install_state);
  
  $form = array();
  // Really too bad tableselect has no easy way to disable a single checkbox...
  if (!empty($featuresets)) {
    foreach($featuresets as $featureset => $details) {
      $elementname = 'featureset-' . $featureset;
      $form[$elementname] = array(
        '#type' => 'checkbox',
        '#disabled' => empty($details['status']) ? TRUE : FALSE, // disabled the widget if its in an inconsistent
        '#default_value' => (FEATURE_SET_ENABLED & $details['status']) ? 1 : 0,
        '#featuresetinfo' => array(
          'featureset' => $details['title'],
          'description' => $details['description'],
          'icon' => empty($details['icon']) ? '' : $details['icon'],
        ),
      );
      
      if (empty($details['status'])) {
        $info = t('This feature set is in an inconsistent state. Please use the following links to correct the feature set.');
        $variables = array(
          'links' => array(
            'feature-set-enable-link' => array(
              'title' => t('Enable'),
              'href' => 'admin/structure/feature-set/enable/' . $featureset,
            ),
            'feature-set-disable-link' => array(
              'title' => t('Disable'),
              'href' => 'admin/structure/feature-set/disable/' . $featureset,
            ),
          ),
        );
        $form[$elementname]['#featuresetinfo']['status'] = $info . theme('links', $variables);
        $form[$elementname]['#featuresetinfo']['class'] = 'warning';
      }
      else {
        if ($form[$elementname]['#default_value']) {
          $form[$elementname]['#featuresetinfo']['status'] = t('OK');
          $form[$elementname]['#featuresetinfo']['class'] = 'status';
        }
        else {
          $form[$elementname]['#featuresetinfo']['status'] = t('Disabled');
          $form[$elementname]['#featuresetinfo']['class'] = 'disabled';
        }
      }
      
    }
  }

  $form['#theme'] = 'feature_set_admin_form';

  $form['submit'] = array('#type' => 'submit', '#value' => t('Update Feature Sets'));

  return $form;
}

/**
 * Theme the administration form
 * Unfortunately tableselect does not have a method to easily disable a single checkbox
 */
function theme_feature_set_admin_form($form) {
  $form = array_pop($form);
  drupal_add_css(drupal_get_path('module', 'feature_set') . '/feature-set.css');
  $header = array('', 'Feature Set', 'status');
  
  $rows = array();
  foreach(element_children($form) as $key) {
    if (strpos($key, 'featureset-') === 0) {
      // set the icon if available.
      if (!empty($form[$key]['#featuresetinfo']['icon'])) {
        $variables = array(
          'path' => $form[$key]['#featuresetinfo']['icon'],
          'alt' => t('@feature-set icon', array('@feature-set' => $form[$key]['#featuresetinfo']['featureset'])),
          'attributes' => array(),
        );
        $icon = '<div class="feature-set-image">' . theme_image($variables) . '</div>';
      }
      else {
        $icon = '';
      }
      $featureset = '<div class="feature-set">';
      $featureset .= '<span class="name">' . $form[$key]['#featuresetinfo']['featureset'] . '</span>';
      if (!empty($form[$key]['#featuresetinfo']['description'])) {
        $featureset .= '<span class="description">' . $form[$key]['#featuresetinfo']['description'] . '</span>';
      }
      $featureset .= '</div>';
    
      $row = array(
        'data' => array(
          drupal_render($form[$key]),
          $icon . $featureset,
          array('data' => $form[$key]['#featuresetinfo']['status'], 'class' => array($form[$key]['#featuresetinfo']['class'], 'messages')),
        ),
      );
      $rows[] = $row;
      
    }
  }
  
  $output = theme('table', array('header' => $header, 'rows' => $rows));
  $output .= drupal_render_children($form);
  
  return $output;
}

/**
 * Submit handler for our form
 *
 * This only processes feature sets that are in a known state.
 */
function feature_set_admin_form_submit($form, &$form_state) {
$featuresets = feature_set_get_featuresets();
  foreach($form_state['values'] as $key => $value) {
    if (strpos($key, 'featureset-') === 0) {
      $featureset = str_replace('featureset-', '', $key);
      // only operate if its in an 'OK' status
      if ( isset($featuresets[$featureset]) && $featuresets[$featureset]['status'] != 0) {
         if ($form_state['values'][$key]) {
          feature_set_enable_feature_set($featuresets[$featureset]);
         }
         else {
          feature_set_disable_feature_set($featuresets[$featureset]);
         }
      }
    }    
  }
}

/**
 * feature_set_disable_url
 * Disable a feature set this is intended to disable an inconsinstent feature set
 */ 
function feature_set_disable_url() {
  $featureset = arg(4);
  $featuresets = $featuresets = feature_set_get_featuresets();
  if (isset($featuresets[$featureset])) {
    feature_set_disable_feature_set($featuresets[$featureset]);
    drupal_goto('admin/structure/feature-set');
  }
  else {
    return t('The feature set "%featureset" could not be found. Please check the link and try again', array('%featureset' => $featureset));
  }
}

/**
 * feature_set_enable_url
 * Enable a feature set this is intended to enable an inconsinstent feature set
 */ 
function feature_set_enable_url() {
  $featureset = arg(4);
  $featuresets = $featuresets = feature_set_get_featuresets();
  if (isset($featuresets[$featureset])) {
    feature_set_enable_feature_set($featuresets[$featureset]);
    drupal_goto('admin/structure/feature-set');
  }
  else {
    return t('The feature set "%featureset" could not be found. Please check the link and try again', array('%featureset' => $featureset));
  }
}
